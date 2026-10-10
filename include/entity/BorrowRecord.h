#ifndef BORROWRECORD_H
#define BORROWRECORD_H

#include <string>
#include <iostream>
using namespace std;

// 借阅记录类，保存借书还书相关信息
class BorrowRecord
{
public:
    string account;      // 读者账号
    string bookIsbn;     // 图书ISBN编号
    string bookName;     // 图书名称
    string borrowDate;   // 借书日期
    string returnDate;   // 还书日期，为空代表未归还

    // 构造函数，带默认参数，支持无参创建对象
    BorrowRecord(string account="", string bookIsbn="", string bookName="",
                 string borrowDate="", string returnDate="");

    // 打印借阅记录信息
    void printRecord() const;

    // 将借阅记录转为逗号分隔字符串，用于保存到文件
    string toString() const;
};

#endif
