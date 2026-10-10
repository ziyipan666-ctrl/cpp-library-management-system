#ifndef READERSERVICE_H
#define READERSERVICE_H
#include "BookService.h"
#include "UserService.h"
#include "BorrowService.h"
#include "BorrowRecord.h"
using namespace std;

/**
 * @brief 读者业务聚合服务，组合service给controller调用
 */
class ReaderService {
private:
    BookService& bookService;
    UserService& userService;
    BorrowService& borrowService;
public:
    ReaderService(BookService& bs, UserService& us, BorrowService& brs);

    // 查询本人借阅记录
    vector<BorrowRecord> getMyBorrowRecords(const string& account);
    // 修改自己密码
    bool modifySelfPassword(const string& account, const string& newPwd);
    // 注销自己账号
    bool deleteSelf(const string& account);
    // 借书
    bool borrowBook(const BorrowRecord& rec);
    // 还书
    bool returnBook(const string& account, const string& bookIsbn, const string& returnDate);
};
#endif
