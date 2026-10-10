#ifndef MAINMENU_H
#define MAINMENU_H
#include "LoginController.h"
using namespace std;

/**
 * @brief 程序主菜单视图：登录、注册、退出系统入口
 */
class MainMenu {
private:
    LoginController& loginCtrl;
public:
    MainMenu(LoginController& lc);
    // 启动主菜单循环
    void showMainLoop();
    // 退出系统
    void exitApp();
};
#endif
