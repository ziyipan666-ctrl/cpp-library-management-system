#ifndef ADMINCONTROLLER_H
#define ADMINCONTROLLER_H
#include <vector>
#include <string>
#include <utility>
#include "AdminService.h"
#include "BookService.h"
#include "BorrowService.h"
#include "UserService.h"
#include "Book.h"
#include "User.h"
#include "BorrowRecord.h"
using namespace std;
/**
 * 管理员控制器，接收管理员菜单发来的操作请求，调用业务层
 */
class AdminController {
private:
    AdminService& adminService;
    BookService& bookService;
    BorrowService& borrowService;
    UserService& userService;
public:
    AdminController(AdminService& as, BookService& bs, UserService& us, BorrowService& brs);

    // 登录接口，main.cpp需要调用
    bool login(const string& account, const string& password);

    // ==========图书相关==========
    bool addBook(const Book& book);
    bool deleteBookByIsbn(const string& isbn);
    bool deleteBookByName(const string& name);
    bool modifyBookByIsbn(const string& oldIsbn, const Book& newBook);
    bool modifyBookByName(const string& oldName, const Book& newBook);
    vector<Book> queryBookByIsbn(const string& isbn);
    vector<Book> queryBookByName(const string& name);
    vector<Book> queryBookByAuthor(const string& author);
    vector<Book> queryBookByPublisher(const string& publisher);
    vector<Book> getAllBookList();
    vector<Book> getBookPage(const vector<Book>& allBooks, int start, int pageSize);
    vector<Book> getNewestTop10Book();

    // ==========用户相关==========
    bool addUser(const string& account, const string& password, int role);
    bool deleteUser(const string& account);
    bool modifyUserPassword(const string& account, const string& newPwd);
    vector<User*> queryUserByAccount(const string& account); // 注意：UserService返回User*，不是User
    vector<User*> getAllUserList();
    vector<User*> getUserPage(const vector<User*>& allUsers, int start, int pageSize);

    // ==========借阅记录相关==========
    vector<BorrowRecord> getAllBorrowRecordList();
    vector<BorrowRecord> getBorrowRecordPage(const vector<BorrowRecord>& allRec, int start, int pageSize);
    vector<pair<string,int>> getBorrowTop10();
};
#endif
