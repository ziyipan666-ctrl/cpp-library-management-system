#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
using namespace std;
//菜单-------------------------------------

//菜单函数
void menus_main();
void menus_reader();
void menus_manager();
void menus_ranklist();
void menus_login();
//退出系统
void ExitSystem();
void managerRun();//管理员运行
void readerRun();//读者运行
//--------------------------------------

class UserManager;
//定义借书、还书
class brInfo
{	public:
		string account;//读者账号
		string ID;//图书编号
		string name;//书名
		string bdate;//借书日期
		string rdate;//还书日期

		brInfo(const string acc,const string id,const string n,const string bd,const string rd);//构造函数

		void bBookPrint()const;//打印借书信息
		void rBookPrint()const;//打印还书信息
		//将借书信息转为字符串
		string toString2();


};

//定义借还书管理类
class brbookManager
{	private:
		vector<brInfo> bbooks;//借书信息数组
		UserManager* userManager; // 用户管理器指针
		string filename;//保护借书记录的文件名

	public:
		//构造函数
		brbookManager(string fn,UserManager* um);
		//用户借书
		void borrowBook();
		//用户还书
		void returnBook();
		//统计借阅次数前十的图书
		void borrowList();
		//从文件中加载用户借书信息
		void loadBorrowBooks();
		//将用户借书信息输入到文件
		void saveBorrowBooks();
		//显示所有借阅记录
		void showAllBorrowRecords();
};
//------------------------------------------------------------------------------------

//定义图书信息类
class BookInfo
{	public:
		string ID;//编号
		string name;//书名
		string author;//作者名
		string publisher;//出版社
		string publishDate;//出版时间
		string price;//价格

		//构造函数
		BookInfo(string id,string n,string a, string p,string pd,string pr);

		//打印图书信息
		void bookprint();

		//将图书信息转为字符串
		string toString();

		//sort比较函数
		static bool cmp(BookInfo a, BookInfo b);
};

//定义图书信息管理
class BookManager
{	private:
		vector<BookInfo> books; //图书信息数组
		string filename;//保存图书信息的文件名

	public:
		//构造函数
		BookManager(string fn);
		//添加图书信息
		void addBook();
		//查找书籍信息
		void findBook();
		//用户查找书籍信息
		void userFindBook();
		//删除图书信息
		void deleteBook();
		//修改图书信息
		void modifyBook();
		//显示所有图书信息
		void showAllBooks();
		//用户显示所有图书信息
		void userShowAllBooks();
		//从文件中加载图书信息
		void loadBooks();
		//将图书信息保存到文件
		void saveBooks();
		//统计出版时间前十的图书
		void newestBookList();
};

class UserInfo
{	public:
		string account;//账号
		string password;//密码
		int role;//角色（1-读者、2-管理员）
		vector<brInfo> borrowHistory;//借书记录
		vector<brInfo> returnHistory;//还书记录

		//构造函数
		UserInfo(string acc,string pwd,int r);

		//打印图书信息
		void Userprint();

		//将用户信息转为字符串
		string toString1();
};

//定义用户信息管理
class UserManager
{	private:
		vector<UserInfo> users; //用户信息数组
		string filename;//保存用户信息的文件名

	public:
		//构造函数
		UserManager(string fn);
		//管理员添加用户信息
		void managerAddUser();
		//用户注册
		void addUser();
		//查找用户信息（包含借书还书记录）
		void findUser();
		//删除用户信息
		void deleteUser();
		//修改用户信息
		void modifyUser();
		//显示所有用户信息
		void showAllUsers();
		//从文件中加载用户信息
		void loadUsers();
		//将用户信息保存到文件
		void saveUsers();
		//验证用户登录
		void login();
		// 添加借书记录
		void addBorrowRecord(const string& account, const brInfo& record);
		// 添加还书记录
		void addReturnRecord(const string& account, const brInfo& record);
		// 显示用户的借书记录
		void showBorrowHistory(const string& account);
		//管理员查询用户借书记录
		void managerShowBorrowHistory(const string& account);
		// 显示用户的还书记录
		void showReturnHistory(const string& account);
		// 用户注销
		void deleteMyself();
		//防止盗用账号
		void getUser(const string& account, const string& password);
};
//---------------------------------------------------------
