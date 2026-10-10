#ifndef READERCONTROLLER_H
#define READERCONTROLLER_H
#include <vector>
#include <string>
#include <utility>
#include "ReaderService.h"
#include "BookService.h"
#include "BorrowService.h"
#include "Book.h"
#include "BorrowRecord.h"
using namespace std;

/**
 * @brief 读者控制器：读者所有操作请求中转
 */
class ReaderController {
private:
    ReaderService& readerService;
    BookService& bookService;
    BorrowService& borrowService;
public:
    ReaderController(ReaderService& rs, BookService& bs, BorrowService& brs);

    //图书查询浏览（公共查询，调用bookService）
    vector<Book> queryBookByIsbn(const string& isbn);
    vector<Book> queryBookByName(const string& name);
    vector<Book> queryBookByAuthor(const string& author);
    vector<Book> queryBookByPublisher(const string& publisher);
    vector<Book> getAllBookList();
    vector<Book> getBookPage(const vector<Book>& allBooks, int start, int pageSize);
    vector<Book> getNewestTop10Book();

    //借还书（读者专属，调用readerService）
    bool borrowBook(const BorrowRecord& rec);
    bool returnBook(const string& account, const string& bookIsbn, const string& returnDate);

    //判断用户这本书是否未归还（公共校验，调用borrowService）
    bool checkIsBorrowedNotReturn(const string& account, const string& bookIsbn);

    //账号（读者专属）
    bool deleteSelfAccount(const string& account);
    bool modifySelfPassword(const string& account, const string& newPwd); //建议补上改密码接口

    //借阅排行榜（公共查询，调用borrowService）
    vector<pair<string,int>> getBorrowTop10();

    //查询本人借阅记录（读者专属，建议加上）
    vector<BorrowRecord> getMyBorrowRecords(const string& account);
};
#endif
