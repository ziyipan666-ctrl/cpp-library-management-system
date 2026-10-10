#include "Reader.h"

// Reader类实现文件，定义了Reader类的成员函数
Reader::Reader(string account, string password)
    : User(account, password, 1)
{
}

// 打印读者信息
void Reader::printInfo() const
{
    cout << "=====【读者账号】=====" << endl;
    User::printInfo();
}
