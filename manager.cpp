#include"function.h"
using namespace std;


//定义用户信息类---------------------------------------------------------
//构造函数
UserInfo::UserInfo(string acc,string pwd,int r)
{	account = acc;
	password = pwd;
	role = r;
}
//打印用户信息
void UserInfo::Userprint()
{	cout << "账号：" << account << endl;
	cout << "密码：" << password << endl;
	cout << "角色：" << (role == 1 ? "读者" : "管理员") << endl;
}
//将用户信息转为字符串
string UserInfo::toString1()
{	string str = account + "," + password + "," + to_string(role);
	return str;
}

//定义用户信息管理类---------------------------------------------------------
//构造函数
UserManager::UserManager(string fn)
{	filename = fn;
	loadUsers();
}

//管理员添加用户信息
void UserManager::managerAddUser()
{	int ch;
	do
	{	string account, password;
		int role;
Loop1:
		cout << "请输入新用户的账号：";
		cin >> account;
		for(int i=0; i<users.size(); i++)
		{	if(users[i].account==account)
			{	cout << "该账号已有人注册，请重新输入！" << endl;
				goto Loop1;
			}
		}
		cout << "请输入新用户的密码：";
		cin >> password;
		cout << "请输入新用户的角色（1-读者、2-管理员）：";
		cin >> role;
		UserInfo user(account, password,role);
		users.push_back(user);
		saveUsers();
		cout << "添加用户成功！" << endl;
		cout << "是否继续添加用户（1-是、2-否）：";
		cin >> ch;
	}
	while(ch==1);
	menus_manager();
}

//用户注册
void UserManager::addUser()
{	string account, password;
	int role;
Loop0:
	cout << "请输入新用户的账号：";
	cin >> account;
	for(int i=0; i<users.size(); i++)
	{	if(users[i].account==account)
		{	cout << "该账号已有人注册，请重新输入！" << endl;
			goto Loop0;
		}
	}
	cout << "请输入新用户的密码：";
	cin >> password;

	UserInfo newuser(account, password,1);//默认为读者
	users.push_back(newuser);
	saveUsers();
	cout << "注册成功！" << endl;
	login();

}
//查找用户信息
void UserManager::findUser()
{	int ch;
	do
	{	cout << "请输入要查找的账号：";
		string acc;
		cin >> acc;

		vector<UserInfo> results;
		for(int i=0; i<users.size(); i++)
		{	if(users[i].account==acc)
			{	results.push_back(users[i]);
			}
		}
		if(results.size()==0)
		{	cout << "未找到该用户信息！" << endl;
		}
		else
		{	cout << "找到该用户" << endl;
			for(int i=0; i<results.size(); i++)
			{	results[i].Userprint();
			    system("pause");
				managerShowBorrowHistory(acc);
				cout << endl;
			}
		}

		cout << "是否选择继续查找（1-是、2-否）：";
		cin >> ch;
	}
	while(ch==1);
	menus_manager();
}

//删除用户信息
void UserManager::deleteUser()
{	int ch;
	do
	{	bool flag=false;
		string acc;
		cout << "请输入要删除的账号：";
		cin >> acc;
		for(int i=0; i<users.size(); i++)
		{	if(users[i].account==acc)
			{	users.erase(users.begin()+i);
				saveUsers();
				cout << "删除成功！" << endl;
				flag=true;
				break;
			}
		}
		if(!flag)
		{	cout << "未找到该用户信息！" << endl;
		}

		cout << "是否选择继续删除（1-是、2-否）：";
		cin >> ch;
	}
	while(ch==1);
	menus_manager();
}

//用户注销账号
void UserManager::deleteMyself()
{	string acc;
	cout << "请输入您的账号：";
	cin >> acc;
	for(int i=0; i<users.size(); i++)
	{	if(users[i].account==acc)
		{	users.erase(users.begin()+i);
			saveUsers();
			break;
		}
	}
	cout << "注销成功！" << endl;
	system("pause");
	menus_main();
}

//修改用户信息
void UserManager::modifyUser()
{	int ch;
	do
	{	bool flag=false;
		string acc;
		cout << "请输入要修改的账号：";
		cin >> acc;
		for(int i=0; i<users.size(); i++)
		{	if(users[i].account==acc)
			{	cout << "请输入新的密码：";
				cin >> users[i].password;
				saveUsers();
				cout << "修改成功！" << endl;
				flag=true;
				break;
			}
		}
		if(!flag)
		{	cout << "未找到该用户信息！" << endl;
		}
		cout << "是否选择继续修改（1-是、2-否）：";
		cin >> ch;
	}
	while(ch==1);
	menus_manager();
}
const int PAGE_SIZE = 5;
//显示所有用户信息
void UserManager::showAllUsers()
{	cout << "以下是所有用户信息：" << endl;
	int page = 1;
	int totalPages = (users.size() + PAGE_SIZE - 1) / PAGE_SIZE;

	while (true)
	{	// 清屏操作，使上一页的图书信息消失
		system("cls");
		int start = (page - 1) * PAGE_SIZE;
		int end = min(start + PAGE_SIZE, static_cast<int>(users.size()));

		for (int i = start; i < end; i++)
		{	users[i].Userprint();
			cout << endl;
		}

		cout << "第 " << page << " 页，共 " << totalPages << " 页" << endl;

		// 提示用户输入操作
		cout << "输入 'n' 查看下一页，'p' 查看上一页，'q' 退出：";
		char choice;
		cin >> choice;

		if (choice == 'n' && page < totalPages)
		{	page++;
		}
		else if (choice == 'p' && page > 1)
		{	page--;
		}
		else if (choice == 'q')
		{	break;
		}
		else
		{	cout << "无效的输入，请重新输入。" << endl;
		}
	}
	system("cls");
	menus_manager();
}

//从文件中加载用户信息
void UserManager::loadUsers()
{	ifstream file(filename);
	if(file.is_open())
	{	string line;
		while(getline(file,line))
		{	string acc = line.substr(0, line.find(","));
			line = line.substr(line.find(",")+1);
			string pwd = line.substr(0,line.find(","));
			line = line.substr(line.find(",")+1);
			int r = stoi(line.substr(0,line.find(",")));
			UserInfo user(acc, pwd, r);
			users.push_back(user);
		}
		file.close();
	}
	else
	{	cout << "文件打开失败！" << endl;
		return;
	}
}

//将用户信息保存到文件
void UserManager::UserManager::saveUsers()
{	ofstream file(filename);
	if(file.is_open())
	{	for(int i=0; i<users.size(); i++)
		{	file << users[i].toString1() << endl;
		}

		file.close();
	}
	else
	{	cout << "文件打开失败！" << endl;
		return;
	}
}

//用户登录
void UserManager::login()
{	bool isRegistered=false;//还未登录
	string acc,pwd;
	int r;
	cout << "请输入账号：";
	cin >> acc;
	cout << "请输入密码：";
	cin >> pwd;
	cout << "请输入角色（1-读者、2-管理员）：";
	cin >> r;
	for(int i=0; i<users.size(); i++)
	{	if(users[i].account==acc && users[i].password==pwd && users[i].role==r)
		{	cout << "登陆成功！" << endl;
			isRegistered=true;
			if(r==1)
			{	menus_reader();
			}
			else
			{	menus_manager();
			}
			break;
		}
	}

	if(!isRegistered)
	{	cout << "登陆失败！" << endl;
	}
}


// 添加借书记录
void UserManager::addBorrowRecord(const string& account, const brInfo& record)
{	for (auto& user : users)
	{	if (user.account == account)
		{	user.borrowHistory.push_back(record);
			return;
		}
	}
}

// 添加还书记录
void UserManager::addReturnRecord(const string& account, const brInfo& record)
{	for (auto& user : users)
	{	if (user.account == account)
		{	user.returnHistory.push_back(record);
			return;
		}
	}
}

// 显示用户的借书记录
void UserManager::showBorrowHistory(const string& account)
{	cout << "========借书记录========" << endl;
	int page = 1;
	int num=0;
	for (const auto& user : users)
	{	if (user.account == account)
		{	for (const auto& record : user.borrowHistory)
			{	num++;
			}
		}
	}
	int totalPages = (num + PAGE_SIZE - 1) / PAGE_SIZE;
	while (true)
	{	// 清屏操作，使上一页的记录信息消失
		system("cls");
		int count=0;
		int start = (page - 1) * PAGE_SIZE;
		int end = min(start + PAGE_SIZE, static_cast<int>(num));
		for (const auto& user : users)
		{	if (user.account == account)
			{	for (const auto& record : user.borrowHistory)
				{	if(count>=end) break;
					cout << "账号: " << record.account << endl;
					cout << "ISBN/ISSN: " << record.ID << endl;
					cout << "书名: " << record.name << endl;
					cout << "借书日期: " << record.bdate << endl;
					cout << "还书日期: " << (record.rdate.empty()? "未还" : record.rdate) << endl;
					cout << "------------------------" << endl;
					count++;
				}
			}
		}
		cout << "第 " << page << " 页，共 " << totalPages << " 页" << endl;
		// 提示用户输入操作
		cout << "输入 'n' 查看下一页，'p' 查看上一页，'q' 退出：";
		char choice;
		cin >> choice;
		if (choice == 'n' && page < totalPages)
		{	page++;
		}
		else if (choice == 'p' && page > 1)
		{	page--;
		}
		else if (choice == 'q')
		{	break;
		}
		else
		{	cout << "无效的输入，请重新输入。" << endl;
		}
	}
	system("cls");
	menus_reader();
}

// 管理员查询用户的借书记录
void UserManager::managerShowBorrowHistory(const string& account)
{	cout << "========该用户的借书记录========" << endl;
	int page = 1;
	int num=0;
	for (const auto& user : users)
	{	if (user.account == account)
		{	for (const auto& record : user.borrowHistory)
			{	num++;
			}
		}
	}
	int totalPages = (num + PAGE_SIZE - 1) / PAGE_SIZE;
	while (true)
	{	
		int count=0;
		int start = (page - 1) * PAGE_SIZE;
		int end = min(start + PAGE_SIZE, static_cast<int>(num));
		for (const auto& user : users)
		{	if (user.account == account)
			{	for (const auto& record : user.borrowHistory)
				{	if(count>=end) break;
					cout << "账号: " << record.account << endl;
					cout << "ISBN/ISSN: " << record.ID << endl;
					cout << "书名: " << record.name << endl;
					cout << "借书日期: " << record.bdate << endl;
					cout << "还书日期: " << (record.rdate.empty()? "未还" : record.rdate) << endl;
					cout << "------------------------" << endl;
					count++;
				}
			}
		}
		cout << "第 " << page << " 页，共 " << totalPages << " 页" << endl;
		// 提示用户输入操作
		cout << "输入 'n' 查看下一页，'p' 查看上一页，'q' 退出：";
		char choice;
		cin >> choice;
		if (choice == 'n' && page < totalPages)
		{	page++;
		}
		else if (choice == 'p' && page > 1)
		{	page--;
		}
		else if (choice == 'q')
		{	break;
		}
		else
		{	cout << "无效的输入，请重新输入。" << endl;
		}
		// 清屏操作，使上一页的记录信息消失
		system("cls");
	}
	menus_manager();
}

// 显示用户的还书记录
void UserManager::showReturnHistory(const string& account)
{	cout << "========还书记录========" << endl;
	bool flag = false; // 添加一个标志来表示是否找到用户
	for (const auto& user : users)
	{	if (user.account == account)
		{	flag = true;
			if (user.borrowHistory.empty())
			{	cout << "该用户没有借书记录！" << endl;
				return;
			}
			for (const auto& record : user.returnHistory)
			{	cout << "账号: " << record.account << endl;
				cout << "ISBN/ISSN: " << record.ID << endl;
				cout << "书名: " << record.name << endl;
				cout << "借书日期: " << record.bdate << endl;
				cout << "还书日期: " << record.rdate << endl;
				cout << "------------------------" << endl;
			}
			system("pause");
			menus_reader();
			return;
		}
	}
	if (!flag)
	{	cout << "未找到该用户！" << endl;
	}
}

//防止盗用账号
void UserManager::getUser(const string& account, const string& password)
{
    // 从用户信息数组中查找用户
    for (const auto& user : users)
    {
        if (user.account == account && user.password == password)
        {
            // 账号验证成功，可以进行后续操作
            cout << "账号验证成功！" << endl;
            return;
        }
    }
    // 账号或密码错误
    cout << "账号或密码错误，请重新输入！" << endl;
    system("pause");
    menus_reader();
}
//--------------------------------------------------------------------