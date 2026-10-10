#include "User.h"

// User类实现文件，定义了User类的成员函数
User::User(string account, string password, int role)
    : account(account), password(password), role(role)
{
}

// 虚析构函数，保证派生类析构正确调用
void User::printInfo() const
{
    cout << "账号: " << account << endl;
    cout << "密码: " << password << endl;
    cout << "角色: " << (role == 1 ? "读者" : "管理员") << endl;
}

// 将用户信息转为逗号分隔字符串，用于保存到文件
string User::toString() const
{
    return account + "," + password + "," + to_string(role);
}
