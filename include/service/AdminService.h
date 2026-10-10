#ifndef ADMINSERVICE_H
#define ADMINSERVICE_H

#include "BookService.h"
#include "UserService.h"
using namespace std;

/**
 * @brief 管理员门面服务：仅管理员专属操作
 */
class AdminService {
private:
    BookService& bookService;
    UserService& userService;
public:
    AdminService(BookService& bs, UserService& us);

    //图书管理
    bool addBook(const Book& book);
    bool deleteBookByIsbn(const string& isbn);
    bool deleteBookByName(const string& name);
    bool modifyBookByIsbn(const string& oldIsbn, const Book& newBook);
    bool modifyBookByName(const string& oldName, const Book& newBook);

    //用户管理
    bool addUser(const string& account, const string& password, int role);
    bool deleteUserByAccount(const string& account);
    bool modifyUserPassword(const string& account, const string& newPwd);
};

#endif
