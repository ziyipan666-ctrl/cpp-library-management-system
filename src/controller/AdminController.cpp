#include "AdminController.h"

AdminController::AdminController(AdminService &as, BookService &bs, UserService &us, BorrowService &brs)
    : adminService(as), bookService(bs), userService(us), borrowService(brs)
{
}
//管理员登录
bool AdminController::login(const string& account, const string& password)
{
    return userService.loginCheck(account, password, 2) != nullptr;
}

//图书管理，调用adminService--------------------------------------------------------------------------
//图书增加
bool AdminController::addBook(const Book& book)
{
    return adminService.addBook(book);
}

//根据isbn删除图书
bool AdminController::deleteBookByIsbn(const string& isbn)
{
    return adminService.deleteBookByIsbn(isbn);
}

//根据书名删除图书
bool AdminController::deleteBookByName(const string& name)
{
    return adminService.deleteBookByName(name);
}

//根据isbn修改图书
bool AdminController::modifyBookByIsbn(const string& oldIsbn, const Book& newBook)
{
    return adminService.modifyBookByIsbn(oldIsbn, newBook);
}

//根据书名修改图书
bool AdminController::modifyBookByName(const string& oldName, const Book& newBook)
{
    return adminService.modifyBookByName(oldName, newBook);
}

//图书查询，直接调用bookService
vector<Book> AdminController::queryBookByIsbn(const string& isbn)
{
    return bookService.queryByIsbn(isbn);
}

//根据书名查询图书
vector<Book> AdminController::queryBookByName(const string& name)
{
    return bookService.queryByName(name);
}

//根据作者查询图书
vector<Book> AdminController::queryBookByAuthor(const string& author)
{
    return bookService.queryByAuthor(author);
}

//根据出版社查询图书
vector<Book> AdminController::queryBookByPublisher(const string& publisher)
{
    return bookService.queryByPublisher(publisher);
}

//获取全部图书列表
vector<shared_ptr<Book>> getAllBookList()
{
    return bookService.getAllBooks();
}

//获取图书分页数据
vector<Book> AdminController::getBookPage(const vector<Book>& allBooks, int start, int pageSize)
{
    return bookService.getPageData(allBooks, start, pageSize);
}

//获取最新10本图书
vector<Book> AdminController::getNewestTop10Book()
{
    return bookService.getNewestTop10();
}

//用户管理，调用adminService-------------------------------------------------------------------------------
//用户增加
bool AdminController::addUser(const string& account, const string& password, int role)
{
    return adminService.addUser(account, password, role);
}

//根据账号删除用户
bool AdminController::deleteUser(const string& account)
{
    return adminService.deleteUserByAccount(account);
}

//根据账号修改用户密码
bool AdminController::modifyUserPassword(const string& account, const string& newPwd)
{
    return adminService.modifyUserPassword(account, newPwd);
}

//根据账号查询用户
vector<User*> AdminController::queryUserByAccount(const string& account)
{
    return userService.queryByAccount(account);
}

//获取全部用户列表
vector<User*> AdminController::getAllUserList()
{
    return userService.getAllUsers();
}

//获取用户分页数据
vector<User*> AdminController::getUserPage(const vector<User*>& allUsers, int start, int pageSize)
{
    return userService.getPageData(allUsers, start, pageSize);
}

//借阅相关，调用borrowService-------------------------------------------------------------------------------
//获取全部借阅记录
vector<BorrowRecord> AdminController::getAllBorrowRecordList()
{
    return borrowService.getAllRecords();
}

//获取借阅记录分页数据
vector<BorrowRecord> AdminController::getBorrowRecordPage(const vector<BorrowRecord>& allRec, int start, int pageSize)
{
    return borrowService.getPageData(allRec, start, pageSize);
}

//获取借阅次数最多的10本图书
vector<pair<string,int>> AdminController::getBorrowTop10()
{
    return borrowService.getBorrowCountTop10();
}