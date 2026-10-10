#include "Admin.h"

Admin::Admin(string account, string password)
    : User(account, password, 2)
{
}

void Admin::printInfo() const
{
    cout << "=====【管理员账号】=====" << endl;
    User::printInfo();
}
