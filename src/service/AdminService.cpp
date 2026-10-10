#include "AdminService.h"

// 构造函数，传入图书服务和用户服务引用
AdminService::AdminService(BookService& bs, UserService& us)
    : bookService(bs), userService(us)
{
}

// 添加图书
bool AdminService::addBook(const Book& book)
{
    return bookService.addBook(book);
}

// 根据ISBN删除图书
bool AdminService::deleteBookByIsbn(const string& isbn)
{
    return bookService.deleteByIsbn(isbn);
}

// 根据书名删除图书
bool AdminService::deleteBookByName(const string& name)
{
    return bookService.deleteByName(name);
}

// 根据ISBN修改图书
bool AdminService::modifyBookByIsbn(const string& oldIsbn, const Book& newBook)
{
    return bookService.modifyByIsbn(oldIsbn, newBook);
}

// 根据书名修改图书
bool AdminService::modifyBookByName(const string& oldName, const Book& newBook)
{
    return bookService.modifyByName(oldName, newBook);
}

// 添加用户
bool AdminService::addUser(const string& account, const string& password, int role)
{
    return userService.addUser(account, password, role);
}

// 删除用户
bool AdminService::deleteUserByAccount(const string& account)
{
    return userService.deleteUserByAccount(account);
}

// 修改用户密码
bool AdminService::modifyUserPassword(const string& account, const string& newPwd)
{
    return userService.modifyPassword(account, newPwd);
}
