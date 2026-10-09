//多级菜单
#include<iostream>
#include"function.h"
using namespace std;

//--------------------------------------------------------------------------
void menus_main()//主菜单
{	system("cls");//清屏
	cout << "========欢迎来到HNU图书馆========" << endl;
	cout << "*********************************" << endl;
	cout << "*         请选择进入模式        *" << endl;
	cout << "*             1.登录            *" << endl;
	cout << "*             2.注册            *" << endl;
	cout << "*             3.退出            *" << endl;
	cout << "*********************************" << endl;
	cout << "请输入您想要执行的功能：" << endl;
	BookManager bm("books.txt");
	UserManager um("users.txt");
	int choice;
	while(true)
	{	cin >> choice;
		switch(choice)
		{	case 1:
				um.login();
				break;
			case 2:
				um.addUser();
				break;
			case 3:
				ExitSystem();
				break;
		}
	}
}
//--------------------------------------------------------------------------
void menus_reader()//读者界面
{	system("cls");//清屏
	cout << "登陆成功！" << endl;
	cout << "*****************************************************" << endl;
	cout << "*                     1.借阅图书                    *" << endl;
	cout << "*                     2.归还图书                    *" << endl;
	cout << "*                     3.搜索图书                    *" << endl;
	cout << "*                     4.排行榜                      *" << endl;
	cout << "*                     5.注销账号                    *" << endl;
	cout << "*                     6.浏览借阅记录                *" << endl;
	cout << "*                     7.浏览图书                    *" << endl;
	cout << "*                     8.返回                        *" << endl;
	cout << "*****************************************************" << endl;
	cout << "请输入您想要执行的功能：" << endl;
	readerRun();
}
//--------------------------------------------------------------------------
void menus_manager()//管理员界面
{	system("cls");//清屏
	cout << "登陆成功！" << endl;
	cout << "*****************************************************" << endl;
	cout << "*       1.增加图书           6.增加读者信息         *" << endl;
	cout << "*       2.删减图书           7.删减读者信息         *" << endl;
	cout << "*       3.修改图书           8.修改读者信息         *" << endl;
	cout << "*       4.查询图书           9.查询读者信息         *" << endl;
	cout << "*       5.显示所有图书信息   10.显示所有用户信息    *" << endl;
	cout << "*       0.返回               11.浏览图书馆借阅记录  *" << endl;
	cout << "*****************************************************" << endl;
	cout << "请输入您想要执行的功能：" << endl;
	managerRun();
}
//--------------------------------------------------------------------------
void menus_ranklist()//排行榜界面
{	system("cls");//清屏
	cout << "*****************************************************" << endl;
	cout << "*                 请输入您要查看的排名              *" << endl;
	cout << "*              1.查看借阅次数前十的图书             *" << endl;
	cout << "*              2.查看最新出版前十的图书             *" << endl;
	cout << "*                       3.返回                      *" << endl;
	cout << "*****************************************************" << endl;
	cout << "请输入您想执行的功能：" << endl;
	BookManager bm("books.txt");
	UserManager um("users.txt");
	UserManager *p;
	p=&um;
	brbookManager brm("borrow.txt", p);
	int choice;
	while(true)
	{	cin >> choice;
		switch(choice)
		{	case 1:
				brm.borrowList();
				cout << "请输入您想执行的功能：" << endl;
				break;
			case 2:
				bm.newestBookList();
				cout << "请输入您想执行的功能：" << endl;
				break;
			case 3:
				menus_reader();
				break;
		}
	}
}
//--------------------------------------------------------------------------
void ExitSystem()//退出系统
{	system("cls");//清屏
	cout << "欢迎您下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}
//--------------------------------------------------------------------------
//运行用户及图书信息管理系统
void managerRun()
{	BookManager bm("books.txt");
	UserManager um("users.txt");
	UserManager *p;
	p=&um;
	brbookManager brm("borrow.txt", p);
	int choice;

	while(true)
	{

		cin >> choice;
		switch(choice)
		{	case 1:
				bm.addBook();
				break;
			case 2:
				bm.deleteBook();
				break;
			case 3:
				bm.modifyBook();
				break;
			case 4:
				bm.findBook();
				break;
			case 6:
				um.managerAddUser();
				break;
			case 7:
				um.deleteUser();
				break;
			case 8:
				um.modifyUser();
				break;
			case 9:
				um.findUser();
				break;
			case 5:
				bm.showAllBooks();
				break;
			case 10:
				um.showAllUsers();
				break;
			case 11:
				brm.showAllBorrowRecords();//浏览图书馆所有借阅记录
				break;
			case 0:
				menus_main();
				break;
		}
		//清屏并重新显示菜单
		system("cls");
	}
}
//--------------------------------------------------------------------------
//运行读者系统
void readerRun()
{	BookManager bm("books.txt");
	UserManager um("users.txt");
	UserManager *p;
	p=&um;
	brbookManager brm("borrow.txt", p);
	int choice;
	string acc,pwd;
	while(true)
	{	cin >> choice;
		switch(choice)
		{	case 1:
				brm.borrowBook();//借阅图书
				break;
			case 2:
				brm.returnBook();//归还图书
				break;
			case 3:
				bm.userFindBook();//搜索图书
				break;
			case 4:
				menus_ranklist();//排行榜
				break;
			case 5:
				um.deleteMyself();//注销账号
				break;
			case 6:
				cout << "请输入您的账号：";
				cin >> acc;
				cout << "请输入您的密码：";
				cin >> pwd;
				um.getUser(acc,pwd);
				um.showBorrowHistory(acc);//查询借还记录
				break;
			case 7:
				bm.userShowAllBooks();//浏览图书
				break;
			case 8:
				menus_main();
				break;
		}
		//清屏并重新显示菜单
		system("cls");
	}
}
//--------------------------------------------------------
