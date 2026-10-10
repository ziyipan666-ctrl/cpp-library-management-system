#ifndef LIBRARY_MANAGEMENT_SYSTEM_USERREPOSITORY_H
#define LIBRARY_MANAGEMENT_SYSTEM_USERREPOSITORY_H

#include <vector>
#include <string>
#include <memory>
#include "../entity/User.h"
#include "../entity/Admin.h"
#include "../entity/Reader.h"
using namespace std;


class UserRepository {
private:
    string filename;
    vector<shared_ptr<User>> users;

    void loadUsers();// 从文件加载用户数据到内存
    void saveUsers();// 保存内存中的用户数据到文件

public:
    UserRepository(const string& filename);// 构造函数，传入用户数据文件路径
    ~UserRepository();// 析构函数，保存用户数据到文件

    shared_ptr<User> findById(const string& id);// 根据ID查找用户
    shared_ptr<User> findByUsername(const string& username); // 根据用户名查找用户
    void addUser(const shared_ptr<User>& user);// 新增用户
    void updateUser(const shared_ptr<User>& user); // 更新用户信息
    void deleteUser(const string& id);// 删除用户
    vector<shared_ptr<User>> getAllUsers() const;// 获取所有用户

    // Service层兼容接口
    vector<User*> loadAllUsers();
    bool saveAllUsers(const vector<User*>& list);
};

#endif