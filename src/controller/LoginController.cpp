#include "LoginController.h"

//登录控制器，调用userService
LoginController::LoginController(UserService& us)
    : userService(us)
{
}

//登录
User* LoginController::doLogin(const string& account, const string& password, int role)
{
    return userService.loginCheck(account, password, role);
}

//注册读者账号
bool LoginController::doRegisterReader(const string& account, const string& password)
{
    return userService.registerReader(account, password);
}
