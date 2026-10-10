#include "ReaderService.h"

// 构造函数，传入图书、用户、借阅服务
ReaderService::ReaderService(BookService& bs, UserService& us, BorrowService& brs)
    : bookService(bs), userService(us), borrowService(brs)
{
}


// 查询本人借阅记录
vector<BorrowRecord> ReaderService::getMyBorrowRecords(const string& account)
{
    vector<BorrowRecord> all = borrowService.getAllRecords();
    vector<BorrowRecord> res;
    for(auto& r : all)
    {
        if(r.account == account)
        {
            res.push_back(r);
        }
    }
    return res;
}

// 修改自己密码
bool ReaderService::modifySelfPassword(const string& account, const string& newPwd)
{
    return userService.modifyPassword(account, newPwd);
}

// 注销自己账号
bool ReaderService::deleteSelf(const string& account)
{
    return userService.deleteSelf(account);
}

// 借阅图书
bool ReaderService::borrowBook(const BorrowRecord& rec)
{
    return borrowService.borrowBook(rec);
}

// 归还图书
bool ReaderService::returnBook(const string& account, const string& bookIsbn, const string& returnDate)
{
    return borrowService.returnBook(account, bookIsbn, returnDate);
}


bool ReaderService::login(const string& account, const string& password)
{
    return userService.loginCheck(account,password,1)!=nullptr;
}
