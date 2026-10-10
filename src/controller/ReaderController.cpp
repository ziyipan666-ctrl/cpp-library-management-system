#include "../../../include/controller/ReaderController.h"

ReaderController::ReaderController(ReaderService& rs, BookService& bs, BorrowService& brs)
    : readerService(rs), bookService(bs), borrowService(brs)
{
}

//图书查询
std::shared_ptr<Book> ReaderController::queryBookById(const std::string& bookId)
{
    return bookService.queryBookById(bookId);
}

std::shared_ptr<Book> ReaderController::queryBookByIsbn(const std::string& isbn)
{
    return bookService.queryBookByIsbn(isbn);
}

std::vector<std::shared_ptr<Book>> ReaderController::queryBookByTitle(const std::string& title)
{
    return bookService.queryBooksByTitle(title);
}

std::vector<std::shared_ptr<Book>> ReaderController::queryBookByAuthor(const std::string& author)
{
    return bookService.queryBooksByAuthor(author);
}

std::vector<std::shared_ptr<Book>> ReaderController::getAllBookList()
{
    return bookService.getAllBooks();
}

std::vector<std::shared_ptr<Book>> ReaderController::getBookPage(const std::vector<std::shared_ptr<Book>>& allBooks, int start, int pageSize)
{
    return bookService.getPageData(allBooks, start, pageSize);
}

//借还书
bool ReaderController::borrowBook(const std::shared_ptr<BorrowRecord>& record)
{
    return readerService.borrowBook(record);
}

bool ReaderController::returnBook(const std::string& userId, const std::string& bookId, const std::string& returnDate)
{
    return readerService.returnBook(userId, bookId, returnDate);
}

bool ReaderController::checkIsBorrowedNotReturn(const std::string& userId, const std::string& bookId)
{
    return borrowService.isUserBorrowNotReturn(userId, bookId);
}

//账号管理
bool ReaderController::deleteSelfAccount(const std::string& userId)
{
    return readerService.deleteSelf(userId);
}

bool ReaderController::modifySelfPassword(const std::string& userId, const std::string& newPwd)
{
    return readerService.modifySelfPassword(userId, newPwd);
}

//借阅记录
std::vector<std::shared_ptr<BorrowRecord>> ReaderController::getMyBorrowRecords(const std::string& userId)
{
    return readerService.getMyBorrowRecords(userId);
}

//排行榜
std::vector<std::pair<std::string,int>> ReaderController::getBorrowTop10()
{
    return borrowService.getBorrowCountTop10();
}