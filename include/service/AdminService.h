#ifndef ADMINSERVICE_H
#define ADMINSERVICE_H

#include "BookService.h"
#include "UserService.h"
using namespace std;

/**
 * 管理员门面服务：仅管理员专属操作
 */
class AdminService {
private:
    BookService& bookService;// 图书服务引用
    UserService& userService;// 用户服务引用
public:
    AdminService(BookService& bs, UserService& us);// 构造函数，传入图书服务和用户服务引用

    //图书管理
    bool addBook(const Book& book);// 添加图书，返回true添加成功
    bool deleteBookByIsbn(const string& isbn);// 根据ISBN删除图书
    bool deleteBookByName(const string& name);// 根据书名删除图书
    bool modifyBookByIsbn(const string& oldIsbn, const Book& newBook);// 根据ISBN修改图书
    bool modifyBookByName(const string& oldName, const Book& newBook);// 根据书名修改图书，返回true修改成功

    //用户管理
    bool addUser(const string& account, const string& password, int role);// 添加用户
    bool deleteUserByAccount(const string& account);// 删除用户
    bool modifyUserPassword(const string& account, const string& newPwd);// 修改用户密码
};

#endif
