#include "ReaderController.h"

bool ReaderController::login(const string& account, const string& password)
{
    return readerService.login(account,password);
}


//读者控制器，调用readerService、bookService、borrowService
ReaderController::ReaderController(ReaderService& rs, BookService& bs, BorrowService& brs)
    : readerService(rs), bookService(bs), borrowService(brs)
{
}

//图书相关，调用readerService=========================================================================
//图书查询--------------------------------------------------------------------------------------
//根据isbn查询图书
vector<Book> ReaderController::queryBookByIsbn(const string& isbn)
{
    return bookService.queryByIsbn(isbn);
}

//根据书名查询图书
vector<Book> ReaderController::queryBookByName(const string& name)
{
    return bookService.queryByName(name);
}

//根据作者查询图书
vector<Book> ReaderController::queryBookByAuthor(const string& author)
{
    return bookService.queryByAuthor(author);
}

//根据出版社查询图书
vector<Book> ReaderController::queryBookByPublisher(const string& publisher)
{
    return bookService.queryByPublisher(publisher);
}

//查询所有图书
vector<Book> ReaderController::getAllBookList()
{
    return bookService.getAllBooks();
}

//分页查询图书
vector<Book> ReaderController::getBookPage(const vector<Book>& allBooks, int start, int pageSize)
{
    return bookService.getPageData(allBooks, start, pageSize);
}

//查询最新10本图书
vector<Book> ReaderController::getNewestTop10Book()
{
    return bookService.getNewestTop10();
}
//-------------------------------------------------------------------------------------------------
//借书
bool ReaderController::borrowBook(const BorrowRecord& rec)
{
    return readerService.borrowBook(rec);
}

//还书
bool ReaderController::returnBook(const string& account, const string& bookIsbn, const string& returnDate)
{
    return readerService.returnBook(account, bookIsbn, returnDate);
}

//判断用户这本书是否未归还
bool ReaderController::checkIsBorrowedNotReturn(const string& account, const string& bookIsbn)
{
    return borrowService.isUserBorrowNotReturn(account, bookIsbn);
}

//账号相关，调用readerService===========================================================================================

//删除账号
bool ReaderController::deleteSelfAccount(const string& account)
{
    return readerService.deleteSelf(account);
}

//修改密码
bool ReaderController::modifySelfPassword(const string& account, const string& newPwd)
{
    return readerService.modifySelfPassword(account, newPwd);
}

//借阅记录
vector<BorrowRecord> ReaderController::getMyBorrowRecords(const string& account)
{
    return readerService.getMyBorrowRecords(account);
}

//排行榜
vector<pair<string,int>> ReaderController::getBorrowTop10()
{
    return borrowService.getBorrowCountTop10();
}
