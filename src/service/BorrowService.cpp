#include "../../../include/service/BorrowService.h"
#include <algorithm>
#include <uuid.h> // For generating UUIDs

BorrowService::BorrowService(BorrowRepository& borrowRepository, BookService& bookService)
    : borrowRepository(borrowRepository), bookService(bookService)
{
}

std::vector<std::shared_ptr<BorrowRecord>> BorrowService::getAllRecords()
{
    return borrowRepository.getAllRecords();
}

bool BorrowService::isUserBorrowNotReturn(const std::string& userId, const std::string& bookId)
{
    std::vector<std::shared_ptr<BorrowRecord>> userRecords = borrowRepository.findByUserId(userId);
    for (const auto& record : userRecords)
    {
        if (record->getBookId() == bookId && record->getReturnDate().empty())
        {
            return true;
        }
    }
    return false;
}

bool BorrowService::borrowBook(const std::shared_ptr<BorrowRecord>& record)
{
    if(isUserBorrowNotReturn(record->getUserId(), record->getBookId()))
    {
        return false; // User already borrowed this book and has not returned it
    }
    // Generate a unique ID if not already set
    if (record->getId().empty()) {
        uuids::uuid_system_generator gen;
        uuids::uuid new_uuid = gen();
        const_cast<std::string&>(record->getId()) = uuids::to_string(new_uuid); // Ugly cast, better to have a setter or generate ID in controller
    }
    borrowRepository.addRecord(record);
    return true;
}

bool BorrowService::returnBook(const std::string& userId, const std::string& bookId, const std::string& returnDate)
{
    std::vector<std::shared_ptr<BorrowRecord>> userRecords = borrowRepository.findByUserId(userId);
    for (auto& record : userRecords)
    {
        if (record->getBookId() == bookId && record->getReturnDate().empty())
        {
            record->setReturnDate(returnDate);
            borrowRepository.updateRecord(record);
            return true;
        }
    }
    return false;
}

std::vector<std::pair<std::string, int>> BorrowService::getBorrowCountTop10()
{
    std::map<std::string, int> bookCount;
    std::vector<std::shared_ptr<BorrowRecord>> allRecords = borrowRepository.getAllRecords();
    for (const auto& record : allRecords)
    {
        std::shared_ptr<Book> book = bookService.queryBookById(record->getBookId());
        if (book) {
            bookCount[book->getTitle()]++;
        }
    }

    std::vector<std::pair<std::string, int>> vec(bookCount.begin(), bookCount.end());
    // Sort by borrow count in descending order
    std::sort(vec.begin(), vec.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.second > b.second;
    });

    std::vector<std::pair<std::string, int>> top10;
    for (int i = 0; i < 10 && i < vec.size(); ++i)
    {
        top10.push_back(vec[i]);
    }
    return top10;
}

std::vector<std::shared_ptr<BorrowRecord>> BorrowService::getMyBorrowRecords(const std::string& userId)
{
    return borrowRepository.findByUserId(userId);
}

std::vector<std::shared_ptr<BorrowRecord>> BorrowService::getPageData(const std::vector<std::shared_ptr<BorrowRecord>>& all, int start, int count)
{
    std::vector<std::shared_ptr<BorrowRecord>> page;
    if(start < 0) return page;
    int end = start + count;
    for (int i = start; i < end && i < (int)all.size(); i++)
    {
        page.push_back(all[i]);
    }
    return page;
}