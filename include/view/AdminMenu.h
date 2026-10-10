#ifndef ADMINMENU_H
#define ADMINMENU_H
#include "AdminController.h"
using namespace std;

/**
 * @brief 管理员菜单视图：管理员全部操作界面
 */
class AdminMenu {
private:
    AdminController& adminCtrl;
public:
    AdminMenu(AdminController& ctrl);
    void showAdminLoop();

private:
    //图书相关子功能
    void menuAddBook();
    void menuDeleteBook();
    void menuModifyBook();
    void menuFindBook();
    void menuShowAllBook();

    //用户管理子功能
    void menuAddUser();
    void menuDeleteUser();
    void menuModifyUser();
    void menuFindUser();
    void menuShowAllUser();

    //借阅相关子功能
    void menuShowAllBorrowRecord();
    void menuShowBorrowTop10(); //新增：借阅排行榜入口，匹配controller接口
};
#endif
