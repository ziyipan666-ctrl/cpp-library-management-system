#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "BorrowRecord.h"
using namespace std;

// 用户基类，读者Reader、管理员Admin继承该类
class User
{
public:
    string account;                 // 用户账号
    string password;                // 用户密码
    int role;                       // 用户角色：1=读者，2=管理员
    vector<BorrowRecord> borrowHistory;  // 用户全部借阅记录
    // 记录中returnDate为空代表未归还，不为空代表已归还

    // 构造函数，带默认参数
    User(string account = "", string password = "", int role = 1);

    // 虚析构，保证派生类析构正确调用
    virtual ~User() = default;

    // 虚函数：打印用户信息，子类可重写
    virtual void printInfo() const;

    // 将用户基础信息转为逗号分隔字符串（只存账号、密码、角色，借阅记录单独存文件）
    string toString() const;
};

#endif
