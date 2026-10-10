#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
using namespace std;
// 管理员类，公有继承User基类
class Admin : public User
{
public:
    // 构造函数，角色固定为2（管理员）
    Admin(string account = "", string password = "");

    // 重写打印信息，增加管理员标识
    void printInfo() const override;
};
#endif
