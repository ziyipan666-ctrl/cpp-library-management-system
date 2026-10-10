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
    ReaderService& readerService;//读者服务层
    BookService& bookService;//图书服务层
    BorrowService& borrowService;//借阅服务层
public:
    ReaderController(ReaderService& rs, BookService& bs, BorrowService& brs);
    bool login(const string& account, const string& password);

    //图书查询浏览（公共查询，调用bookService）
    vector<Book> queryBookByIsbn(const string& isbn);//根据isbn查询图书
    vector<Book> queryBookByName(const string& name);//根据名称查询图书
    vector<Book> queryBookByAuthor(const string& author);//根据作者查询图书
    vector<Book> queryBookByPublisher(const string& publisher);//根据出版社查询图书
    vector<Book> getAllBookList();//获取全部图书列表
    vector<Book> getBookPage(const vector<Book>& allBooks, int start, int pageSize);//获取页码图书列表
    vector<Book> getNewestTop10Book();//获取最新10本图书

    //借还书（读者专属，调用readerService）
    bool borrowBook(const BorrowRecord& rec); //借书
    bool returnBook(const string& account, const string& bookIsbn, const string& returnDate);//还书

    //判断用户这本书是否未归还（公共校验，调用borrowService）
    bool checkIsBorrowedNotReturn(const string& account, const string& bookIsbn);

    //账号（读者专属）
    bool deleteSelfAccount(const string& account);//注销账号
    bool modifySelfPassword(const string& account, const string& newPwd); //修改密码

    //借阅排行榜（公共查询，调用borrowService）
    vector<pair<string,int>> getBorrowTop10();

    //查询本人借阅记录
    vector<BorrowRecord> getMyBorrowRecords(const string& account);
};
#endif

