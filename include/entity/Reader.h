#ifndef READER_H
#define READER_H
#include "User.h"
using namespace std;
// 读者类，公有继承User基类
class Reader : public User
{
public:
    // 构造函数，角色固定为1（读者）
    Reader(string account = "", string password = "");

    // 重写打印信息，增加读者标识
    void printInfo() const override;
};
#endif
