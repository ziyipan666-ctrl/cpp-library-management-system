#include "../../../include/controller/AdminController.h"

AdminController::AdminController(AdminService &as, BookService &bs, UserService &us, BorrowService &brs)
    : adminService(as), bookService(bs), userService(us), borrowService(brs)
{
}

// 图书增删改，调用adminService
bool AdminController::addBook(const std::shared_ptr<Book>& book)
{
    return adminService.addBook(book);
}

bool AdminController::deleteBookById(const std::string& bookId)
{
    return adminService.deleteBookById(bookId);
}

bool AdminController::updateBook(const std::shared_ptr<Book>& book)
{
    return adminService.updateBook(book);
}

//图书查询，直接调用bookService
std::shared_ptr<Book> AdminController::queryBookById(const std::string& bookId)
{
    return bookService.queryBookById(bookId);
}

std::shared_ptr<Book> AdminController::queryBookByIsbn(const std::string& isbn)
{
    return bookService.queryBookByIsbn(isbn);
}

std::vector<std::shared_ptr<Book>> AdminController::queryBookByTitle(const std::string& title)
{
    return bookService.queryBooksByTitle(title);
}

std::vector<std::shared_ptr<Book>> AdminController::queryBookByAuthor(const std::string& author)
{
    return bookService.queryBooksByAuthor(author);
}

std::vector<std::shared_ptr<Book>> AdminController::getAllBookList()
{
    return bookService.getAllBooks();
}

std::vector<std::shared_ptr<Book>> AdminController::getBookPage(const std::vector<std::shared_ptr<Book>>& allBooks, int start, int pageSize)
{
    return bookService.getPageData(allBooks, start, pageSize);
}

//用户管理
bool AdminController::addUser(const std::string& username, const std::string& password, const std::string& role)
{
    return adminService.addUser(username, password, role);
}

bool AdminController::deleteUserById(const std::string& userId)
{
    return adminService.deleteUserById(userId);
}

bool AdminController::modifyUserPassword(const std::string& userId, const std::string& newPwd)
{
    return adminService.modifyUserPassword(userId, newPwd);
}

std::shared_ptr<User> AdminController::queryUserById(const std::string& userId)
{
    return userService.getUserById(userId);
}

std::vector<std::shared_ptr<User>> AdminController::getAllUserList()
{
    return userService.getAllUsers();
}

std::vector<std::shared_ptr<User>> AdminController::getUserPage(const std::vector<std::shared_ptr<User>>& allUsers, int start, int pageSize)
{
    // UserService might need a getPageData method, or implement here
    std::vector<std::shared_ptr<User>> page;
    int end = start + pageSize;
    for (int i = start; i < end && i < (int)allUsers.size(); i++)
    {
        page.push_back(allUsers[i]);
    }
    return page;
}

//借阅相关，调用borrowService
std::vector<std::shared_ptr<BorrowRecord>> AdminController::getAllBorrowRecordList()
{
    return borrowService.getAllRecords();
}

std::vector<std::shared_ptr<BorrowRecord>> AdminController::getBorrowRecordPage(const std::vector<std::shared_ptr<BorrowRecord>>& allRec, int start, int pageSize)
{
    return borrowService.getPageData(allRec, start, pageSize);
}

std::vector<std::pair<std::string,int>> AdminController::getBorrowTop10()
{
    return borrowService.getBorrowCountTop10();
}