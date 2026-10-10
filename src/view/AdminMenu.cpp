#include "AdminMenu.h"
#include "MainMenu.h"
#include <iostream>
#include <cstdlib>
using namespace std;

AdminMenu::AdminMenu(AdminController& ctrl)
    : adminCtrl(ctrl)
{ }

void AdminMenu::showAdminLoop()
{
    while(true)
    {
        system("cls");
        cout << "登录成功！【管理员界面】 " << endl;
        cout << "********************************************************" << endl;
        cout << "* 1.增加图书     6.增加读者信息                       *" << endl;
        cout << "* 2.删减图书     7.删减读者信息                       *" << endl;
        cout << "* 3.修改图书     8.修改读者信息                       *" << endl;
        cout << "* 4.查询图书     9.查询读者信息                       *" << endl;
        cout << "* 5.显示所有图书信息  10.显示所有用户信息              *" << endl;
        cout << "* 0.返回        11.浏览图书馆借阅记录                  *" << endl;
        cout << "********************************************************" << endl;
        cout << "请输入您想要执行的功能： " << endl;

        int op;
        cin >> op;
        switch(op)
        {
            case 1: menuAddBook(); break;
            case 2: menuDeleteBook(); break;
            case 3: menuModifyBook(); break;
            case 4: menuFindBook(); break;
            case 5: menuShowAllBook(); break;
            case 6: menuAddUser(); break;
            case 7: menuDeleteUser(); break;
            case 8: menuModifyUser(); break;
            case 9: menuFindUser(); break;
            case 10: menuShowAllUser(); break;
            case 11: menuShowAllBorrowRecord(); break;
            case 0: return;
            default:
                cout << "无效选项"<<endl;
                system("pause");
                break;
        }
    }
}

void AdminMenu::menuAddBook()
{
    int ch;
    do{
        string isbn,name,author,publisher,pubDate,price;
        cout << "请输入ISBN/ISSN: "; cin>>isbn;
        cout << "请输入书名: "; cin>>name;
        cout << "请输入作者: "; cin>>author;
        cout << "请输入出版社: "; cin>>publisher;
        cout << "请输入出版时间（格式如20241224）: "; cin>>pubDate;
        cout << "请输入价格: "; cin>>price;

        Book b(isbn,name,author,publisher,pubDate,price);
        bool res = adminCtrl.addBook(b);
        if(res) cout << "添加书籍成功！" << endl;
        else cout << "添加失败！"<<endl;

        cout << "是否继续添加（1‑是、2‑否）: ";
        cin >> ch;
    }while(ch ==1);
}

void AdminMenu::menuDeleteBook()
{
    int ch;
    do{
        int sel;
        cout << "请选择删除方式：1‑按ISBN/ISSN、2‑按书名" << endl;
        cin >> sel;
        bool ok = false;
        if(sel ==1)
        {
            string isbn;
            cout << "输入要删除ISBN:"; cin>>isbn;
            ok = adminCtrl.deleteBookByIsbn(isbn);
        }
        else if(sel ==2)
        {
            string name;
            cout << "输入要删除书名:"; cin>>name;
            ok = adminCtrl.deleteBookByName(name);
        }
        if(ok) cout << "删除成功！" << endl;
        else cout << "未找到该图书信息！" << endl;
        cout << "是否继续删除（1‑是、2‑否）:"; cin>>ch;
    }while(ch==1);
}

void AdminMenu::menuModifyBook()
{
    int ch;
    do{
        int sel;
        cout << "选择修改方式：1‑按ISBN、2‑按书名"<<endl;
        cin>>sel;
        if(sel == 1)
        {
            string oldIsbn;
            cout << "输入待修改ISBN:"; cin>>oldIsbn;
            Book nb;
            cout << "输入新ISBN:"; cin>>nb.isbn;
            cout << "输入新书名:"; cin>>nb.name;
            cout << "输入新作者:"; cin>>nb.author;
            cout << "输入新出版社:"; cin>>nb.publisher;
            cout << "输入新出版时间:"; cin>>nb.publishDate;
            cout << "输入新价格:"; cin>>nb.price;
            bool ret = adminCtrl.modifyBookByIsbn(oldIsbn, nb);
            if(ret) cout<<"修改成功！"<<endl;
            else cout<<"未找到图书！"<<endl;
        }
        else if(sel ==2)
        {
            string oldName;
            cout << "输入待修改书名:"; cin>>oldName;
            Book nb;
            cout << "输入新ISBN:"; cin>>nb.isbn;
            cout << "输入新书名:"; cin>>nb.name;
            cout << "输入新作者:"; cin>>nb.author;
            cout << "输入新出版社:"; cin>>nb.publisher;
            cout << "输入新出版时间:"; cin>>nb.publishDate;
            cout << "输入新价格:"; cin>>nb.price;
            bool ret = adminCtrl.modifyBookByName(oldName, nb);
            if(ret) cout<<"修改成功！"<<endl;
            else cout<<"未找到图书！"<<endl;
        }
        cout << "是否继续修改（1‑是，2‑否）:"; cin>>ch;
    }while(ch==1);
}

void AdminMenu::menuFindBook()
{
    int ch;
    do{
        cout << "请选择查询方式：1‑书名，2‑ISBN，3‑作者，4‑出版社，5‑返回"<<endl;
        int op; cin>>op;
        vector<Book> res;
        if(op ==1)
        {
            string n; cout<<"输入书名:";cin>>n;
            res = adminCtrl.queryBookByName(n);
        }
        else if(op ==2)
        {
            string id; cout<<"输入ISBN:";cin>>id;
            res = adminCtrl.queryBookByIsbn(id);
        }
        else if(op ==3)
        {
            string au; cout<<"输入作者:";cin>>au;
            res = adminCtrl.queryBookByAuthor(au);
        }
        else if(op ==4)
        {
            string pub; cout<<"输入出版社:";cin>>pub;
            res = adminCtrl.queryBookByPublisher(pub);
        }
        else break;

        if(res.empty())
        {
            cout << "未找到相关图书！"<<endl;
        }
        else
        {
            cout << "共找到" << res.size() << "本书" << endl;
            for(auto &b : res)
            {
                b.printInfo();
                cout << "-----------------"<<endl;
            }
        }
        cout << "是否继续查询(1是2否):"; cin>>ch;
    }while(ch==1);
}

void AdminMenu::menuShowAllBook()
{
    vector<Book> all = adminCtrl.getAllBookList();
    const int PAGE_SIZE = 10;
    int page =1;
    int totalPage = (all.size() + PAGE_SIZE -1)/PAGE_SIZE;
    while(true)
    {
        system("cls");
        int start = (page-1)*PAGE_SIZE;
        vector<Book> pageData = adminCtrl.getBookPage(all, start, PAGE_SIZE);
        for(auto &b : pageData)
        {
            b.printInfo();
            cout<<endl;
        }
        cout << "第"<<page<<"页，共"<<totalPage<<"页"<<endl;
        cout << "n下一页 p上一页 q退出:";
        char c; cin>>c;
        if(c == 'n' && page < totalPage) page++;
        else if(c == 'p' && page>1) page--;
        else if(c == 'q') break;
    }
}

void AdminMenu::menuAddUser()
{
    int ch;
    do{
        string acc,pwd;
        int role;
        cout << "输入账号:"; cin>>acc;
        cout << "输入密码:"; cin>>pwd;
        cout << "角色1读者，2管理员:"; cin>>role;
        bool r = adminCtrl.addUser(acc,pwd,role);
        if(r) cout<<"添加用户成功"<<endl;
        else cout<<"账号已存在"<<endl;
        cout << "继续添加？1是2否:"; cin>>ch;
    }while(ch ==1);
}

void AdminMenu::menuDeleteUser()
{
    int ch;
    do{
        string acc;
        cout << "输入待删除账号:"; cin>>acc;
        bool r = adminCtrl.deleteUser(acc);
        if(r) cout<<"删除成功"<<endl;
        else cout<<"未找到用户"<<endl;
        cout << "继续删除？1是2否:"; cin>>ch;
    }while(ch==1);
}

void AdminMenu::menuModifyUser()
{
    int ch;
    do{
        string acc,pwdNew;
        cout << "输入账号:"; cin>>acc;
        cout << "输入新密码:"; cin>>pwdNew;
        bool r = adminCtrl.modifyUserPassword(acc,pwdNew);
        if(r) cout<<"修改成功"<<endl;
        else cout<<"未找到用户"<<endl;
        cout << "继续修改？1是2否:"; cin>>ch;
    }while(ch==1);
}

void AdminMenu::menuFindUser()
{
    int ch;
    do{
        string acc;
        cout << "输入要查找账号:"; cin>>acc;
        vector<User*> res = adminCtrl.queryUserByAccount(acc);
        if(res.empty())
        {
            cout << "未找到用户"<<endl;
        }
        else
        {
            for(auto &u : res)
            {
                u->printInfo();
            }
        }
        cout << "继续查询？1是2否:"; cin>>ch;
    }while(ch==1);
}

void AdminMenu::menuShowAllUser()
{
    vector<User*> all = adminCtrl.getAllUserList();
    const int PAGE_SIZE = 5;
    int page = 1;
    int totalPage = (all.size()+PAGE_SIZE-1)/PAGE_SIZE;
    while(true)
    {
        system("cls");
        int start = (page-1)*PAGE_SIZE;
        vector<User*> pageData = adminCtrl.getUserPage(all, start, PAGE_SIZE);
        for(auto &u : pageData)
        {
            u->printInfo();
            cout << "------"<<endl;
        }
        cout << "第"<<page<<"页，共"<<totalPage<<"页"<<endl;
        char op;
        cout << "n下一页 p上一页 q退出:"; cin>>op;
        if(op =='n' && page < totalPage) page++;
        else if(op =='p' && page>1) page--;
        else if(op =='q') break;
    }
}

void AdminMenu::menuShowAllBorrowRecord()
{
    vector<BorrowRecord> all = adminCtrl.getAllBorrowRecordList();
    const int PAGE_SIZE = 10;
    int page = 1;
    int totalPage = (all.size()+PAGE_SIZE-1)/PAGE_SIZE;
    while(true)
    {
        system("cls");
        int start = (page-1)*PAGE_SIZE;
        vector<BorrowRecord> pageData = adminCtrl.getBorrowRecordPage(all, start, PAGE_SIZE);
        for(auto &r : pageData)
        {
            r.printRecord();
            cout << "---------"<<endl;
        }
        cout << "第"<<page<<"页，共"<<totalPage<<"页"<<endl;
        char op;
        cout << "n下一页 p上一页 q退出:"; cin>>op;
        if(op =='n' && page < totalPage) page++;
        else if(op =='p' && page>1) page--;
        else if(op =='q') break;
    }
}
