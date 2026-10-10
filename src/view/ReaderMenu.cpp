#include "ReaderMenu.h"
#include "MainMenu.h"
#include <iostream>
#include <cstdlib>
using namespace std;

ReaderMenu::ReaderMenu(ReaderController& ctrl)
    : readerCtrl(ctrl)
{ }

// 显示读者菜单循环
void ReaderMenu::showReaderLoop()
{
    while(true)
    {
        system("cls");
        cout << "登录成功！【读者界面】 " << endl;
        cout << "********************************************" << endl;
        cout << "*        1.借阅图书                        *" << endl;
        cout << "*        2.归还图书                        *" << endl;
        cout << "*        3.搜索图书                        *" << endl;
        cout << "*        4.排行榜                          *" << endl;
        cout << "*        5.注销账号                        *" << endl;
        cout << "*        6.浏览借阅记录                    *" << endl;
        cout << "*        7.浏览图书                        *" << endl;
        cout << "*        8.返回                            *" << endl;
        cout << "********************************************" << endl;
        cout << "请输入您想要执行的功能： " << endl;

        int op;
        cin >> op;
        switch(op)
        {
            case 1: menuBorrowBook(); break;
            case 2: menuReturnBook(); break;
            case 3: menuSearchBook(); break;
            case 4: menuShowRank(); break;
            case 5: menuDeleteSelfAccount(); break;
            case 6: menuShowBorrowHistory(); break;
            case 7: menuBrowseAllBook(); break;
            case 8: return;
            default:
                cout << "无效选项！"<<endl;
                system("pause");
                break;
        }
    }
}

// 借书功能
void ReaderMenu::menuBorrowBook()
{
    int ch;
    do{
        string acc,pwd,isbn,name,borrowDate;
        cout << "账号："; cin>>acc;
        cout << "密码："; cin>>pwd;
        cout << "图书ISBN:"; cin>>isbn;
        cout << "图书书名:"; cin>>name;
        cout << "借书日期(20241225):"; cin>>borrowDate;

        //判断是否未归还
        bool hasBorrow = readerCtrl.checkIsBorrowedNotReturn(acc,isbn);
        if(hasBorrow)
        {
            cout << "该图书你已经借过尚未归还，不能重复借阅！"<<endl;
            system("pause");
            break;
        }
        BorrowRecord br(acc,isbn,name,borrowDate,"");
        bool res = readerCtrl.borrowBook(br);
        if(res) cout << "借书成功！"<<endl;
        else cout << "借书失败！"<<endl;

        cout << "是否继续借书（1‑是 2‑否）:"; cin>>ch;
    }while(ch == 1);
}

// 归还图书功能
void ReaderMenu::menuReturnBook()
{
    int ch;
    do{
        string acc,pwd,isbn,name,retDate;
        cout << "账号:"; cin>>acc;
        cout << "密码:"; cin>>pwd;
        cout << "图书ISBN:"; cin>>isbn;
        cout << "书名:"; cin>>name;
        cout << "还书日期:"; cin>>retDate;

        bool ok = readerCtrl.returnBook(acc,isbn,retDate);
        if(ok) cout << "还书成功！"<<endl;
        else cout << "未找到借阅记录！"<<endl;

        cout << "继续还书？1是2否:"; cin>>ch;
    }while(ch == 1);
}

// 查询图书功能
void ReaderMenu::menuSearchBook()
{
    int ch;
    do{
        cout << "查询方式：1书名，2ISBN，3作者，4出版社，5返回"<<endl;
        int op; cin>>op;
        vector<Book> res;
        if(op == 1)
        {
            string n; cout<<"书名：";cin>>n;
            res = readerCtrl.queryBookByName(n);
        }
        else if(op ==2)
        {
            string id; cout<<"ISBN:";cin>>id;
            res = readerCtrl.queryBookByIsbn(id);
        }
        else if(op ==3)
        {
            string au; cout<<"作者:";cin>>au;
            res = readerCtrl.queryBookByAuthor(au);
        }
        else if(op ==4)
        {
            string pub; cout<<"出版社:";cin>>pub;
            res = readerCtrl.queryBookByPublisher(pub);
        }
        else break;

        if(res.empty())
        {
            cout << "没有找到图书"<<endl;
        }
        else
        {
            cout << "找到" << res.size() << "本："<<endl;
            for(auto &b : res)
            {
                b.printInfo();
                cout << "-------"<<endl;
            }
        }
        cout << "继续查询？1是2否:"; cin>>ch;
    }while(ch == 1);
}

// 显示排行榜功能
void ReaderMenu::menuShowRank()
{
    while(true)
    {
        system("cls");
        cout << "====排行榜===="<<endl;
        cout << "1.借阅次数前十图书"<<endl;
        cout << "2.最新出版前十图书"<<endl;
        cout << "3.返回"<<endl;
        int op; cin>>op;
        if(op == 1)
        {
            auto top = readerCtrl.getBorrowTop10();
            int cnt=1;
            for(auto &p : top)
            {
                cout << cnt << ". 书名："<<p.first << " 借阅次数：" << p.second <<endl;
                cnt++;
                if(cnt>10) break;
            }
        }
        else if(op == 2)
        {
            auto top = readerCtrl.getNewestTop10Book();
            int cnt=1;
            for(auto &b : top)
            {
                cout << cnt << ". ";
                b.printInfo();
                cnt++;
                if(cnt>10) break;
            }
        }
        else if(op == 3)
        {
            break;
        }
        system("pause");
    }
}

// 注销账号功能
void ReaderMenu::menuDeleteSelfAccount()
{
    string acc;
    cout << "输入你的账号："; cin>>acc;
    bool ok = readerCtrl.deleteSelfAccount(acc);
    if(ok)
    {
        cout << "账号注销成功！"<<endl;
    }
    else
    {
        cout << "注销失败，账号不存在！"<<endl;
    }
    system("pause");
}

// 显示借阅记录功能
void ReaderMenu::menuShowBorrowHistory()
{
    string account;
    cout << "请输入你的账号：";
    cin >> account;
    vector<BorrowRecord> records = readerCtrl.getMyBorrowRecords(account);
    if(records.empty())
    {
        cout << "暂无借阅记录！" << endl;
    }
    else
    {
        for(auto &r : records)
        {
            r.printRecord();
            cout << "-----------------" << endl;
        }
    }
    system("pause");
}

// 浏览全部图书功能
void ReaderMenu::menuBrowseAllBook()
{
    vector<Book> all = readerCtrl.getAllBookList();
    const int PAGE_SIZE =10;
    int page = 1;
    int totalPage = (all.size()+PAGE_SIZE-1)/PAGE_SIZE;
    while(true)
    {
        system("cls");
        int start = (page-1)*PAGE_SIZE;
        vector<Book> pageData = readerCtrl.getBookPage(all, start, PAGE_SIZE);
        for(auto &b : pageData)
        {
            b.printInfo();
            cout << endl;
        }
        cout << "第"<<page<<"页 /共"<<totalPage<<"页"<<endl;
        char c;
        cout << "n下一页 p上一页 q退出:"; cin>>c;
        if(c =='n' && page < totalPage) page++;
        else if(c =='p' && page>1) page--;
        else if(c =='q') break;
    }
}
