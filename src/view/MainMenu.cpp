#include "MainMenu.h"
#include "AdminMenu.h"
#include "ReaderMenu.h"
#include <iostream>
#include <cstdlib>
using namespace std;

MainMenu::MainMenu(LoginController& lc)
    : loginCtrl(lc)
{ }

// 显示主菜单循环
void MainMenu::showMainLoop()
{
    while(true)
    {
        system("cls");
        cout << "========欢迎来到HNU图书馆========" << endl;
        cout << "********************************************" << endl;
        cout << "*            请选择进入模式                 *" << endl;
        cout << "*             1.登录                       *" << endl;
        cout << "*             2.注册                       *" << endl;
        cout << "*             3.退出                       *" << endl;
        cout << "********************************************" << endl;
        cout << "请输入您想要执行的功能： " << endl;

        int choice;
        cin >> choice;
        if(choice == 1)
        {
            string acc,pwd;
            int role;
            cout << "请输入账号: ";
            cin >> acc;
            cout << "请输入密码: ";
            cin >> pwd;
            cout << "请输入角色（1‑读者、2‑管理员）: ";
            cin >> role;

            User* user = loginCtrl.doLogin(acc,pwd,role);
            if(user != nullptr)
            {
                cout << "登录成功！" << endl;
                system("pause");
                if(role == 1)
                {
                    // 后续：这里需要ReaderController实例，不要用单例
                    // ReaderMenu readerMenu(readerCtrl);
                    // readerMenu.showReaderLoop();
                }
                else
                {
                    // AdminMenu adminMenu(adminCtrl);
                    // adminMenu.showAdminLoop();
                }
            }
            else
            {
                cout << "登录失败！账号密码角色不匹配" << endl;
                system("pause");
            }
        }
        else if(choice == 2)
        {
            string acc,pwd;
            ReInputAccount:
            cout << "请输入新用户的账号: ";
            cin >> acc;
            cout << "请输入新用户的密码: ";
            cin >> pwd;
            bool ok = loginCtrl.doRegisterReader(acc,pwd);
            if(!ok)
            {
                cout << "该账号已有人注册，请重新输入！" << endl;
                goto ReInputAccount;
            }
            cout << "注册成功！请登录。" << endl;
            system("pause");
        }
        else if(choice == 3)
        {
            exitApp();
        }
        else
        {
            cout << "输入选项无效，请重新选择！" << endl;
            system("pause");
        }
    }
}

// 退出应用
void MainMenu::exitApp()
{
    system("cls");
    cout << "欢迎您下次使用" << endl;
    system("pause");
    exit(0);
}
