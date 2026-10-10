#include <iostream>
#include <cstdlib>
#include "AdminController.h"
#include "ReaderController.h"
#include "AdminMenu.h"
#include "ReaderMenu.h"
#include "BookService.h"
#include "UserService.h"
#include "BorrowService.h"
#include "AdminService.h"
#include "ReaderService.h"

using namespace std;

int main()
{
    // 初始化服务层
    BookService bookService("data/books.txt");
    UserService userService("data/users.txt", "data/borrow_records.txt");
    BorrowService borrowService("data/borrow_records.txt");
    AdminService adminService(bookService, userService);
    ReaderService readerService(bookService, userService, borrowService);

    // 初始化控制器
    AdminController adminCtrl(adminService, bookService, userService, borrowService);
    ReaderController readerCtrl(readerService, bookService, borrowService);

    // 菜单对象（无单例，直接构造传入控制器引用）
    AdminMenu adminMenu(adminCtrl);
    ReaderMenu readerMenu(readerCtrl);

    int mainOp;
    while (true)
    {
        system("cls");
        cout << "==========图书管理系统==========" << endl;
        cout << "1. 管理员登录" << endl;
        cout << "2. 读者登录" << endl;
        cout << "0. 退出系统" << endl;
        cout << "================================" << endl;
        cout << "请选择：";
        cin >> mainOp;

        if (mainOp == 1)
        {
            string acc, pwd;
            cout << "管理员账号：";
            cin >> acc;
            cout << "管理员密码：";
            cin >> pwd;

            if (adminCtrl.login(acc, pwd))
            {
                cout << "管理员登录成功！" << endl;
                system("pause");
                adminMenu.showAdminLoop();
            }
            else
            {
                cout << "账号或密码错误！" << endl;
                system("pause");
            }
        }
        else if (mainOp == 2)
        {
            string acc, pwd;
            cout << "读者账号：";
            cin >> acc;
            cout << "读者密码：";
            cin >> pwd;

            if (readerCtrl.login(acc, pwd))
            {
                cout << "读者登录成功！" << endl;
                system("pause");
                readerMenu.showReaderLoop();
            }
            else
            {
                cout << "账号或密码错误！" << endl;
                system("pause");
            }
        }
        else if (mainOp == 0)
        {
            cout << "系统退出，再见！" << endl;
            break;
        }
        else
        {
            cout << "无效选项！" << endl;
            system("pause");
        }
    }
    return 0;
}
