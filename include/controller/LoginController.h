#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include <string>
#include "UserService.h"
#include "User.h"
using namespace std;

/**
 * @brief 登录注册控制器，处理登录、读者注册请求
 */
class LoginController {
private:
    UserService& userService;
public:
    LoginController(UserService& us);

    /**
     * 用户登录校验
     * 账号
     * 密码
     * 角色 1读者 /2管理员
     * 成功返回User对象指针；失败返回nullptr
     */
    User* doLogin(const string& account, const string& password, int role);

    /**
     * 读者账号注册
     * 新账号
     * 密码
     * true注册成功；false账号已存在/失败
     */
    bool doRegisterReader(const string& account, const string& password);
};
#endif
