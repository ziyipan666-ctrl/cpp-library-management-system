#include "BorrowRecord.h"

// BorrowRecord类实现文件，定义了BorrowRecord类的成员函数
BorrowRecord::BorrowRecord(string account, string bookIsbn, string bookName,
                           string borrowDate, string returnDate)
    : account(account), bookIsbn(bookIsbn), bookName(bookName),
      borrowDate(borrowDate), returnDate(returnDate)
{

}

// 打印借阅记录信息
void BorrowRecord::printRecord() const
{
    cout << "读者账号: " << account << endl;
    cout << "图书ISBN: " << bookIsbn << endl;
    cout << "书名: " << bookName << endl;
    cout << "借书日期: " << borrowDate << endl;
    if (!returnDate.empty())
    {
        cout << "还书日期: " << returnDate << endl;
    }
}

// 将借阅记录转为逗号分隔字符串，用于保存到文件
string BorrowRecord::toString() const
{
    return account + "," + bookIsbn + "," + bookName + "," + borrowDate + "," + returnDate;
}
