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
#include <memory>
using namespace std;
/**
 * 管理员控制器，接收管理员菜单发来的操作请求，调用业务层
 */
class AdminController {
private:
    AdminService& adminService;//管理员服务层
    BookService& bookService;//图书服务层
    BorrowService& borrowService;//借阅服务层
    UserService& userService;//用户服务层
public:
    AdminController(AdminService& as, BookService& bs, UserService& us, BorrowService& brs);

    // 登录接口，main.cpp需要调用
    bool login(const string& account, const string& password);

    // ==========图书相关==========
    bool addBook(const Book& book);//添加图书
    bool deleteBookByIsbn(const string& isbn);//根据isbn删除图书
    bool deleteBookByName(const string& name);//根据书名删除图书
    bool modifyBookByIsbn(const string& oldIsbn, const Book& newBook);//根据isbn修改图书
    bool modifyBookByName(const string& oldName, const Book& newBook);//根据书名修改图书
    vector<Book> queryBookByIsbn(const string& isbn);//根据isbn查询图书
    vector<Book> queryBookByName(const string& name);//根据书名查询图书
    vector<Book> queryBookByAuthor(const string& author);//根据作者查询图书
    vector<Book> queryBookByPublisher(const string& publisher);//根据出版社查询图书
    vector<shared_ptr<Book>> getAllBookList();//获取全部图书列表
    vector<Book> getBookPage(const vector<Book>& allBooks, int start, int pageSize);//分页查询图书
    vector<Book> getNewestTop10Book();//获取最新10本图书

    // ==========用户相关==========
    bool addUser(const string& account, const string& password, int role);//添加用户
    bool deleteUser(const string& account);//删除用户
    bool modifyUserPassword(const string& account, const string& newPwd);//修改用户密码
    vector<User*> queryUserByAccount(const string& account); //根据账号查询用户基本信息和借还记录
    vector<User*> getAllUserList();//获取全部用户列表
    vector<User*> getUserPage(const vector<User*>& allUsers, int start, int pageSize); //分页查询用户

    // ==========借阅记录相关==========
    vector<BorrowRecord> getAllBorrowRecordList();//获取全部借阅记录
    vector<BorrowRecord> getBorrowRecordPage(const vector<BorrowRecord>& allRec, int start, int pageSize);//分页查询借阅记录
    vector<pair<string,int>> getBorrowTop10();//获取借阅次数最多的10本图书
};
#endif
