#ifndef USERSERVICE_H
#define USERSERVICE_H

#include <vector>
#include <string>
#include "User.h"
#include "UserRepository.h"
#include "BorrowRepository.h"
#include "BorrowRecord.h"
using namespace std;

// 用户业务服务层：登录、注册、增删改查用户
class UserService
{
private:
    UserRepository repo;
    BorrowRepository borrowRepo;

    void fillBorrowHistory(User* user);
public:
    const static int PAGE_SIZE;

    UserService(string userFilePath, string borrowFilePath);

    // 获取全部用户（基类指针，支持多态）
    vector<User*> getAllUsers();

    // 账号是否已经存在
    bool isAccountExist(const string& account);

    // 注册读者，账号不能重复，返回true注册成功
    bool registerReader(const string& account, const string& password);

    // 管理员新增用户，可以指定角色
    bool addUser(const string& account, const string& password, int role);

    // 删除用户，按账号
    bool deleteUserByAccount(const string& account);

    // 修改用户密码
    bool modifyPassword(const string& account, const string& newPwd);

    // 根据账号查询用户
    vector<User*> queryByAccount(const string& account);

    // 登录校验：账号、密码、角色，成功返回指针，失败返回nullptr
    User* loginCheck(const string& account, const string& password, int role);

    // 用户注销自己账号
    bool deleteSelf(const string& account);

    // 给指定账号追加借书记录
    bool appendBorrowRecord(const string& account, const BorrowRecord& br);

    // 给指定账号追加还书记录
    bool appendReturnRecord(const string& account, const BorrowRecord& br);

    // 分页
    vector<User*> getPageData(const vector<User*>& all, int start, int count);
};

#endif