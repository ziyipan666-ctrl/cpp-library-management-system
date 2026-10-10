#ifndef ADMINMENU_H
#define ADMINMENU_H
#include "AdminController.h"
using namespace std;

/**
 * 管理员菜单视图：管理员全部操作界面
 */
class AdminMenu {
private:
    AdminController& adminCtrl;//管理员控制器引用
public:
    AdminMenu(AdminController& ctrl);//构造函数，传入管理员控制器引用
    void showAdminLoop();//显示管理员菜单循环

private:
    //图书相关子功能
    void menuAddBook();//添加图书
    void menuDeleteBook();//删除图书
    void menuModifyBook();//修改图书
    void menuFindBook();//查找图书
    void menuShowAllBook();//显示全部图书

    //用户管理子功能
    void menuAddUser();//添加用户
    void menuDeleteUser();//删除用户
    void menuModifyUser();//修改用户
    void menuFindUser();//查找用户
    void menuShowAllUser();//显示全部用户

    //借阅相关子功能
    void menuShowAllBorrowRecord();//显示全部借阅记录
    void menuShowMyBorrowRecord();//显示某个用户的借阅记录
    void menuShowBorrowTop10(); //新增：借阅排行榜入口，匹配controller接口
};
#endif

