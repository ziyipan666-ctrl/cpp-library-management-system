#include "User.h"

User::User(string account, string password, int role)
    : account(account), password(password), role(role)
{
}

void User::printInfo() const
{
    cout << "账号: " << account << endl;
    cout << "密码: " << password << endl;
    cout << "角色: " << (role == 1 ? "读者" : "管理员") << endl;
}

string User::toString() const
{
    return account + "," + password + "," + to_string(role);
}
