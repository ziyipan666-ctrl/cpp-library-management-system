#include "../../../include/service/AdminService.h"

AdminService::AdminService(BookService& bs, UserService& us)
    : bookService(bs), userService(us)
{
}

bool AdminService::addBook(const std::shared_ptr<Book>& book)
{
    return bookService.addBook(book);
}

bool AdminService::deleteBookById(const std::string& bookId)
{
    return bookService.deleteBook(bookId);
}

bool AdminService::updateBook(const std::shared_ptr<Book>& book)
{
    return bookService.updateBook(book);
}

bool AdminService::addUser(const std::string& username, const std::string& password, const std::string& role)
{
    return userService.registerUser(username, password, role);
}

bool AdminService::deleteUserById(const std::string& userId)
{
    return userService.deleteUser(userId);
}

bool AdminService::modifyUserPassword(const std::string& userId, const std::string& newPwd)
{
    return userService.updateUserPassword(userId, newPwd);
}