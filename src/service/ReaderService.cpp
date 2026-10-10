#include "../../../include/service/ReaderService.h"

ReaderService::ReaderService(BookService& bs, UserService& us, BorrowService& brs)
    : bookService(bs), userService(us), borrowService(brs)
{
}

std::vector<std::shared_ptr<BorrowRecord>> ReaderService::getMyBorrowRecords(const std::string& userId)
{
    return borrowService.getMyBorrowRecords(userId);
}

bool ReaderService::modifySelfPassword(const std::string& userId, const std::string& newPwd)
{
    return userService.updateUserPassword(userId, newPwd);
}

bool ReaderService::deleteSelf(const std::string& userId)
{
    return userService.deleteUser(userId);
}

bool ReaderService::borrowBook(const std::shared_ptr<BorrowRecord>& record)
{
    // Need to ensure the book exists and is available
    std::shared_ptr<Book> book = bookService.queryBookById(record->getBookId());
    if (!book || book->getQuantity() <= 0) {
        return false; // Book not found or out of stock
    }

    if (borrowService.borrowBook(record)) {
        // Decrease book quantity
        book->setQuantity(book->getQuantity() - 1);
        bookService.updateBook(book);
        return true;
    }
    return false;
}

bool ReaderService::returnBook(const std::string& userId, const std::string& bookId, const std::string& returnDate)
{
    if (borrowService.returnBook(userId, bookId, returnDate)) {
        // Increase book quantity
        std::shared_ptr<Book> book = bookService.queryBookById(bookId);
        if (book) {
            book->setQuantity(book->getQuantity() + 1);
            bookService.updateBook(book);
        }
        return true;
    }
    return false;
}