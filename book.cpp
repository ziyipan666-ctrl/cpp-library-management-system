#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include"function.h"
using namespace std;

//定义图书信息类---------------------------------------------------------
//构造函数
BookInfo::BookInfo(string id,string n,string a, string p,string pd,string pr)
{	ID=id;
	name=n;
	author=a;
	publisher=p;
	publishDate=pd;
	price=pr;
}

//打印图书信息
void BookInfo::bookprint()
{	cout << "ISBN/ISSN：" << ID << endl;
	cout << "书名：" << name << endl;
	cout << "作者：" << author << endl;
	cout << "出版社：" << publisher << endl;
	cout << "出版时间（格式：如20241208）：" << publishDate << endl;
	cout << "价格：" << price << endl;
}

bool BookInfo::cmp(BookInfo a, BookInfo b)
{	return a.publishDate > b.publishDate;
}

//将图书信息转为字符串
string BookInfo::toString()
{	string str = ID + "," + name + "," + author + "," + publisher + "," + publishDate + "," + price;
	return str;
}

//定义图书信息管理-----------------------------------------------------------
//构造函数
BookManager::BookManager(string fn)
{	filename = fn;
	loadBooks();
}

//添加图书信息
void BookManager::addBook()
{	int ch;
	do
	{	string id;
		string name, author, publisher,publishDate,price;

		cout << "请输入ISBN/ISSN：";
		cin >> id;
		cout << "请输入书名：";
		cin >> name;
		cout << "请输入作者：";
		cin >> author;
		cout << "请输入出版社：";
		cin >> publisher;
		cout << "请输入出版时间（格式：如20241208）：";
		cin >> publishDate;
		cout << "请输入价格：";
		cin >> price;
		BookInfo book(id, name, author, publisher,publishDate,price);
		books.push_back(book);
		saveBooks();
		cout << "添加书籍成功！" << endl;
		cout << "是否继续添加（1-是、2-否）：";
		cin >> ch;
	}
	while(ch==1);
	menus_manager();
}

//查找书籍信息
void BookManager::findBook()
{	int ch;

	do
	{	cout << "请选择查询方式：" << endl;
		cout << "1-按书名、2-按ISBN/ISSN、3-按作者、4-按出版社、5-返回" << endl;
		int num;
		cin >> num;
		if(num==1)
		{	string name;
			cout << "请输入要查找的书名：";
			cin >> name;
			vector<BookInfo> results;
			for(int i=0; i<books.size(); i++)
			{	if(books[i].name==name)
				{	results.push_back(books[i]);
				}
			}
			if(results.size()==0)
			{	cout << "未找到该书名的图书信息！" << endl;
			}
			else
			{	cout << "共找到" << results.size() << "本书：" << endl;
				for(int i=0; i<results.size(); i++)
				{	results[i].bookprint();
					cout << endl;
				}
			}
		}
		else if(num==2)
		{	string id;
			cout << "请输入要查找的ISBN/ISSN：";
			cin >> id;
			vector<BookInfo> results;
			for(int i=0; i<books.size(); i++)
			{	if(books[i].ID==id)
				{	results.push_back(books[i]);
				}
			}
			if(results.size()==0)
			{	cout << "未找到该书名的图书信息！" << endl;
			}
			else
			{	cout << "共找到" << results.size() << "本书：" << endl;
				for(int i=0; i<results.size(); i++)
				{	results[i].bookprint();
					cout << endl;
				}
			}
		}
		else if(num==3)
		{	string author;
			cout << "请输入要查找的作者：";
			cin >> author;
			vector<BookInfo> results;
			for(int i=0; i<books.size(); i++)
			{	if(books[i].author==author)
				{	results.push_back(books[i]);
				}
			}
			if(results.size()==0)
			{	cout << "未找到该书名的图书信息！" << endl;
			}
			else
			{	// 按照书名进行字典序排序
				sort(results.begin(), results.end(), [](const BookInfo& a, const BookInfo& b)
				{	return a.name < b.name;
				});
				cout << "共找到" << results.size() << "本书：" << endl;
				for(int i=0; i<results.size(); i++)
				{	results[i].bookprint();
					cout << endl;
				}
			}
		}
		else if(num==4)
		{	string publisher;
			cout << "请输入要查找的出版社：";
			cin >> publisher;
			vector<BookInfo> results;
			for(int i=0; i<books.size(); i++)
			{	if(books[i].publisher==publisher)
				{	results.push_back(books[i]);
				}
			}
			if(results.size()==0)
			{	cout << "未找到该书名的图书信息！" << endl;
			}
			else
			{	// 按照书名进行字典序排序
				sort(results.begin(), results.end(), [](const BookInfo& a, const BookInfo& b)
				{	return a.name < b.name;
				});
				cout << "共找到" << results.size() << "本书：" << endl;
				for(int i=0; i<results.size(); i++)
				{	results[i].bookprint();
					cout << endl;
				}
			}
		}
		else if(num==5)
		{
			break;
		}
		cout << "是否选择继续查询（1-是、2-否）：";
		cin >> ch;
	}
	while(ch==1);
	menus_manager();
}
//用户查找图书
void BookManager::userFindBook()
{	int ch;
	do
	{	cout << "请选择查询方式：" << endl;
		cout << "1-按书名、2-按ISBN/ISSN、3-按作者、4-按出版社、5-返回" << endl;
		int num;
		cin >> num;
		if(num==1)
		{	string name;
			cout << "请输入要查找的书名：";
			cin >> name;
			vector<BookInfo> results;
			for(int i=0; i<books.size(); i++)
			{	if(books[i].name==name)
				{	results.push_back(books[i]);
				}
			}
			if(results.size()==0)
			{	cout << "未找到该书名的图书信息！" << endl;
			}
			else
			{	cout << "共找到" << results.size() << "本书：" << endl;
				for(int i=0; i<results.size(); i++)
				{	results[i].bookprint();
					cout << endl;
				}
			}
		}
		else if(num==2)
		{	string id;
			cout << "请输入要查找的ISBN/ISSN：";
			cin >> id;
			vector<BookInfo> results;
			for(int i=0; i<books.size(); i++)
			{	if(books[i].ID==id)
				{	results.push_back(books[i]);
				}
			}
			if(results.size()==0)
			{	cout << "未找到该书名的图书信息！" << endl;
			}
			else
			{	cout << "共找到" << results.size() << "本书：" << endl;
				for(int i=0; i<results.size(); i++)
				{	results[i].bookprint();
					cout << endl;
				}
			}
		}
		else if(num==3)
		{	string author;
			cout << "请输入要查找的作者：";
			cin >> author;
			vector<BookInfo> results;
			for(int i=0; i<books.size(); i++)
			{	if(books[i].author==author)
				{	results.push_back(books[i]);
				}
			}
			if(results.size()==0)
			{	cout << "未找到该书名的图书信息！" << endl;
			}
			else
			{	// 按照书名进行字典序排序
				sort(results.begin(), results.end(), [](const BookInfo& a, const BookInfo& b)
				{	return a.name < b.name;
				});
				cout << "共找到" << results.size() << "本书：" << endl;
				for(int i=0; i<results.size(); i++)
				{	results[i].bookprint();
					cout << endl;
				}
			}
		}
		else if(num==4)
		{	string publisher;
			cout << "请输入要查找的出版社：";
			cin >> publisher;
			vector<BookInfo> results;
			for(int i=0; i<books.size(); i++)
			{	if(books[i].publisher==publisher)
				{	results.push_back(books[i]);
				}
			}
			if(results.size()==0)
			{	cout << "未找到该书名的图书信息！" << endl;
			}
			else
			{	// 按照书名进行字典序排序
				sort(results.begin(), results.end(), [](const BookInfo& a, const BookInfo& b)
				{	return a.name < b.name;
				});
				cout << "共找到" << results.size() << "本书：" << endl;
				for(int i=0; i<results.size(); i++)
				{	results[i].bookprint();
					cout << endl;
				}
			}
		}
		else if(num==5)
		{
			break;
		}
		cout << "是否选择继续查询（1-是、2-否）：";
		cin >> ch;
	}
	while(ch==1);
	menus_reader();
}
//删除图书信息
void BookManager::deleteBook()
{	int ch,choice=0;
	do
	{	bool flag=false;
		string id,name;
		cout << "请选择删除方式：1-按ISBN/ISSN、2-按书名" << endl;
		cin >> choice;
		if(choice==1)
		{	cout << "请输入要删除的ISBN/ISSN：";
			cin >> id;
			for(int i=0; i<books.size(); i++)
			{	if(books[i].ID==id)
				{	books.erase(books.begin()+i);
					saveBooks();
					cout << "删除成功！" << endl;
					flag=true;
					break;
				}
			}
			if(!flag)
			{	cout << "未找到该图书信息！" << endl;
			}
		}
		else if(choice==2)
		{	cout << "请输入要删除的书名：";
			cin >> name;
			for(int i=0; i<books.size(); i++)
			{	if(books[i].name==name)
				{	books.erase(books.begin()+i);
					saveBooks();
					cout << "删除成功！" << endl;
					flag=true;
					break;
				}
			}
			if(!flag)
			{	cout << "未找到该图书信息！" << endl;
			}
		}
		cout << "是否选择继续删除（1-是、2-否）：";
		cin >> ch;
	}
	while(ch==1);
	menus_manager();
}

//修改图书信息
void BookManager::modifyBook()
{	int ch,choice=0;
	do
	{	bool flag=false;
		string id,name;
		cout << "请选择修改方式：1-按ISBN/ISSN、2-按书名" << endl;
		cin >> choice;
		if(choice==1)
		{

			cout << "请输入要修改的ISBN/ISSN：";
			cin >> id;
			int xuanze=0;
			for(int i=0; i<books.size(); i++)
			{	if(books[i].ID==id)
				{	cout << "请输入要修改的信息：1-ISBN/ISSN、2-书名、3-作者、4-出版时间、5-价格" << endl;
					cin >> xuanze;
					switch (xuanze)
					{	case 1:
							cout << "请输入新的ISBN/ISSN：";
							cin >> books[i].ID;
							break;
						case 2:
							cout << "请输入新的书名：";
							cin >> books[i].name;
							break;
						case 3:
							cout << "请输入新的作者：";
							cin >> books[i].author;
							break;
						case 4:
							cout << "请输入新的出版时间（格式：如20241208）：";
							cin >> books[i].publishDate;
							break;
						case 5:
							cout << "请输入新的价格：";
							cin >> books[i].price;
							break;
					}
					saveBooks();
					cout << "修改成功！" << endl;
					flag=true;
					break;
				}
			}
			if(!flag)
			{	cout << "未找到该图书信息！" << endl;
			}
		}
		else if(choice==2)
		{	cout << "请输入要修改的书名：";
			cin >> name;
			int xuanze=0;
			for(int i=0; i<books.size(); i++)
			{	if(books[i].name==name)
				{	cout << "请输入要修改的信息：1-ISBN/ISSN、2-书名、3-作者、4-出版时间、5-价格" << endl;
					cin >> xuanze;
					switch (xuanze)
					{	case 1:
							cout << "请输入新的ISBN/ISSN：";
							cin >> books[i].ID;
							break;
						case 2:
							cout << "请输入新的书名：";
							cin >> books[i].name;
							break;
						case 3:
							cout << "请输入新的作者：";
							cin >> books[i].author;
							break;
						case 4:
							cout << "请输入新的出版时间（格式：如20241208）：";
							cin >> books[i].publishDate;
							break;
						case 5:
							cout << "请输入新的价格：";
							cin >> books[i].price;
							break;
					}
					saveBooks();
					cout << "修改成功！" << endl;
					flag=true;
					break;
				}
			}
			if(!flag)
			{	cout << "未找到该图书信息！" << endl;
			}
		}
		cout << "是否选择继续修改（1-是、2-否）：";
		cin >> ch;
	}
	while(ch==1);
	menus_manager();
}
const int PAGE_SIZE = 5;
//显示所有图书信息
void BookManager::showAllBooks()
{	cout << "以下是所有图书信息：" << endl;
	int page = 1;// 初始化当前页码为 1
	int totalPages = (books.size() + PAGE_SIZE - 1) / PAGE_SIZE;
    // 根据图书数量和每页显示的数量计算总页数
	while (true)// 进入一个无限循环
	{	// 清屏操作，使上一页的图书信息消失
		system("cls");
		int start = (page - 1) * PAGE_SIZE;// 计算当前页的起始图书索引
		int end = min(start + PAGE_SIZE, static_cast<int>(books.size()));// 计算当前页的结束图书索引

		for (int i = start; i < end; i++)
		{	books[i].bookprint();// 调用 books 数组中当前索引位置的图书的 bookprint 方法进行打印
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
	// 添加以下代码来暂停程序
	system("cls");
	menus_manager();
}

//用户显示所有图书
void BookManager::userShowAllBooks()
{	cout << "以下是该图书馆所含有的图书及信息：" << endl;
	int page = 1;
	int totalPages = (books.size() + PAGE_SIZE - 1) / PAGE_SIZE;

	while (true)
	{	// 清屏操作，使上一页的图书信息消失
		system("cls");
		int start = (page - 1) * PAGE_SIZE;
		int end = min(start + PAGE_SIZE, static_cast<int>(books.size()));

		for (int i = start; i < end; i++)
		{	books[i].bookprint();
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
	// 添加以下代码来暂停程序
	system("cls");
	menus_reader();
}
//从文件中加载图书信息
void BookManager::loadBooks()
{	ifstream file(filename);
	if(file.is_open())
	{	string line;
		while(getline(file,line))
		{	string id = line.substr(0, line.find(","));
			line = line.substr(line.find(",")+1);
			string name = line.substr(0,line.find(","));
			line = line.substr(line.find(",")+1);
			string author = line.substr(0,line.find(","));
			line = line.substr(line.find(",")+1);
			string publisher = line.substr(0,line.find(","));
			line = line.substr(line.find(",")+1);
			string publishDate = line.substr(0,line.find(","));
			line = line.substr(line.find(",")+1);
			string price = line.substr(0,line.find(","));
			BookInfo book(id, name, author, publisher,publishDate,price);
			books.push_back(book);
		}
		file.close();
	}
	else
	{	cout << "文件打开失败！" << endl;
		return;
	}
}

//将图书信息保存到文件
void BookManager::saveBooks()
{	ofstream file(filename);
	if(file.is_open())
	{	for(int i=0; i<books.size(); i++)
		{	file << books[i].toString() << endl;
		}

		file.close();
	}
	else
	{	cout << "文件打开失败！" << endl;
		return;
	}
}

//统计最新出版时间前十的图书
void BookManager::newestBookList()
{	sort(books.begin(),books.end(),BookInfo::cmp);
	cout << "*************最新出版前十的图书*************" << endl;
	int count=0;
	for(const auto&book:books)
	{	if(count>=10) break;
		cout << count + 1 << ". "<< "ISBN/ISSN：" << book.ID << "  " << "书名: " << book.name << " " << "作者: " << book.author << " " << "出版社:" << book.publisher << " "<< "出版时间: " << book.publishDate << endl;
		count++;
	}
}
//---------------------------------------------------------------------------
//定义借书还书类
//构造函数
brInfo::brInfo(string acc,string id,string n,string bd,string rd)
{	account=acc;
	ID=id;
	name=n;
	bdate=bd;
	rdate=rd;
}

//打印借书
void brInfo::bBookPrint()const
{	cout << "读者账号：" << account << endl;
	cout << "图书的ISBN/ISSN：" << ID << endl;
	cout << "书名：" << name << endl;
	cout << "借书日期（格式：如20241208）：" << bdate << endl;
	if (!rdate.empty())
	{	cout << "还书日期（格式：如20241208）：" << rdate << endl;
	}
}

//将借书信息转为字符串
string brInfo::toString2()
{	string str = account + "," + ID + "," + name + "," + bdate + "," + rdate;
	return str;
}
//---------------------------------------------------------------------------

//定义借还书管理类
brbookManager::brbookManager(string fn,UserManager* um)
{	filename=fn;
	userManager = um;
	loadBorrowBooks();

}

//从文件中加载用户借书信息
void brbookManager::loadBorrowBooks()
{	ifstream file(filename);
	if(file.is_open())
	{	string line;
		while(getline(file,line))
		{	string account = line.substr(0, line.find(","));
			line = line.substr(line.find(",")+1);
			string id = line.substr(0,line.find(","));
			line = line.substr(line.find(",")+1);
			string name = line.substr(0,line.find(","));
			line = line.substr(line.find(",")+1);
			string bdate = line.substr(0,line.find(","));
			line = line.substr(line.find(",")+1);
			string rdate = line.substr(0,line.find(","));

			brInfo borrow(account, id, name, bdate, rdate);
			// 将借书记录添加到对应的用户中
			userManager->addBorrowRecord(account, borrow);
			// 将还书记录添加到对应的用户中
			userManager->addReturnRecord(account, borrow);
			bbooks.push_back(borrow);
		}
		file.close();
	}
	else
	{	cout << "文件打开失败！" << endl;
		return;
	}
}
// 将用户借书信息保存到文件
void brbookManager::saveBorrowBooks()
{	ofstream file(filename);
	if(file.is_open())
	{	for (auto& bbook : bbooks)
		{	file << bbook.toString2() << endl;
		}
		file.close();
	}
	else
	{	cout << "文件打开失败！" << endl;
		return;
	}
}
//用户借书
void brbookManager::borrowBook()
{	int ch;
	string acc,pwd,id,n,bd,rd="";
	cout << "请输入账号：";
	cin >> acc;
	cout << "请输入密码：";
	cin >> pwd;
	// 从 UserManager 中获取用户信息
	userManager->getUser(acc,pwd);
	do
	{	cout << "请输入图书的ISBN/ISSN：";
		cin >> id;
		cout << "请输入书名：";
		cin >> n;
		cout << "请输入借书日期（格式：如20241208）：";
		cin >> bd;

		// 检查是否有重复的借书记录
		for (const auto& bbook : bbooks)
		{	if (bbook.account == acc && bbook.ID == id && bbook.rdate.empty())
			{	cout << "该读者已借阅此书，不能再次借阅！" << endl;
				system("pause");
				menus_reader();
			}
		}
		brInfo newBorrow(acc, id, n, bd, rd);
		// 将借书记录添加到 UserManager 中
		userManager->addBorrowRecord(acc, newBorrow);
		bbooks.push_back(newBorrow);
		saveBorrowBooks();
		cout << "借书成功！" << endl;
		cout << "是否选择继续借书（1-是、2-否）：";
		cin >> ch;
	}
	while(ch==1);
	menus_reader();
}
//用户还书
void brbookManager::returnBook()
{	int ch;
	bool flag=false;
	string acc,pwd,id,n,rd;
	cout << "请输入账号：";
	cin >> acc;
	cout << "请输入密码：";
	cin >> pwd;
	// 从 UserManager 中获取用户信息
	userManager->getUser(acc,pwd);
	do
	{	cout << "请输入图书的ISBN/ISSN：";
		cin >> id;
		cout << "请输入书名：";
		cin >> n;
		cout << "请输入还书日期（格式：如20241208）：";
		cin >> rd;
		for (auto& bbook : bbooks)
		{	if (bbook.account == acc && bbook.ID == id && bbook.rdate.empty())
			{	bbook.rdate = rd;
				// 将还书记录添加到 UserManager 中
				userManager->addReturnRecord(acc, bbook);
				saveBorrowBooks();
				flag=true;
				break;
			}
		}
		if (flag)
		{	cout << "还书成功！" << endl;
		}
		else
		{	cout << "未找到该用户的借书记录或该书未被该用户借阅或该书已归还！" << endl;
		}
		cout << "是否选择继续还书（1-是、2-否）：";
		cin >> ch;
	}
	while(ch==1);
	menus_reader();
}
// 统计借阅次数前十的图书
void brbookManager::borrowList()
{	map<string, int> bookCount;
	for (const auto& bbook : bbooks)
	{	bookCount[bbook.name]++;
	}

	vector<pair<string, int>> sortedBooks(bookCount.begin(), bookCount.end());
	sort(sortedBooks.begin(), sortedBooks.end(), [](const pair<string, int>& a,const pair<string, int>& b)
	{	return a.second > b.second;
	});

	cout << "========借阅次数前十的图书========" << endl;
	int count = 0;
	for (const auto& pair : sortedBooks)
	{	if (count >= 10) break;
		cout << count + 1 << ". "<< "书名: " << pair.first << " " << "借阅次数: " << pair.second << endl;
		count++;
	}
}

void brbookManager::showAllBorrowRecords()
{	cout << "以下是所有借书记录：" << endl;
	int page = 1;
	int totalPages = (bbooks.size() + PAGE_SIZE - 1) / PAGE_SIZE;

	while (true)
	{	// 清屏操作，使上一页的记录信息消失
		system("cls");

		int start = (page - 1) * PAGE_SIZE;
		int end = min(start + PAGE_SIZE, static_cast<int>(bbooks.size()));

		for (int i = start; i < end; i++)
		{	bbooks[i].bBookPrint();
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
	// 恢复控制台的正常输出
	system("cls");
	menus_manager();
}