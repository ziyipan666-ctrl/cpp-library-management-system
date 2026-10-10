#include "BookService.h"
#include <algorithm>

const int BookService::PAGE_SIZE = 10;

// 构造函数，传入图书数据文件路径
BookService::BookService(string filePath)
    : repo(filePath)
{
}

// 获取全部图书
vector<Book> BookService::getAllBooks()
{
    return repo.loadAllBooks();
}

// 添加图书
bool BookService::addBook(const Book& book)
{
    vector<Book> list = repo.loadAllBooks();
    list.push_back(book);
    return repo.saveAllBooks(list);
}

// 根据isbn删除图书
bool BookService::deleteByIsbn(const string& isbn)
{
    vector<Book> list = repo.loadAllBooks();
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        if (it->isbn == isbn)
        {
            list.erase(it);
            return repo.saveAllBooks(list);
        }
    }
    return false;
}

// 根据书名删除图书（匹配第一个）
bool BookService::deleteByName(const string& name)
{
    vector<Book> list = repo.loadAllBooks();
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        if (it->name == name)
        {
            list.erase(it);
            return repo.saveAllBooks(list);
        }
    }
    return false;
}

// 根据isbn修改图书
bool BookService::modifyByIsbn(const string& oldIsbn, const Book& newBook)
{
    vector<Book> list = repo.loadAllBooks();
    for (auto& b : list)
    {
        if (b.isbn == oldIsbn)
        {
            b = newBook;
            return repo.saveAllBooks(list);
        }
    }
    return false;
}

// 根据书名修改图书（匹配第一个）
bool BookService::modifyByName(const string& oldName, const Book& newBook)
{
    vector<Book> list = repo.loadAllBooks();
    for (auto& b : list)
    {
        if (b.name == oldName)
        {
            b = newBook;
            return repo.saveAllBooks(list);
        }
    }
    return false;
}

// 查询：按isbn
vector<Book> BookService::queryByIsbn(const string& isbn)
{
    vector<Book> res;
    vector<Book> all = repo.loadAllBooks();
    for (auto& b : all)
    {
        if (b.isbn == isbn)
            res.push_back(b);
    }
    return res;
}

// 查询：按书名
vector<Book> BookService::queryByName(const string& name)
{
    vector<Book> res;
    vector<Book> all = repo.loadAllBooks();
    for (auto& b : all)
    {
        if (b.name == name)
            res.push_back(b);
    }
    return res;
}

// 查询：按作者，结果按书名字典序排序
vector<Book> BookService::queryByAuthor(const string& author)
{
    vector<Book> res;
    vector<Book> all = repo.loadAllBooks();
    for (auto& b : all)
    {
        if (b.author == author)
            res.push_back(b);
    }
    // 书名字典序升序
    sort(res.begin(), res.end(), [](const Book& a, const Book& b) {
        return a.name < b.name;
    });
    return res;
}

// 查询：按出版社，结果按书名字典序排序
vector<Book> BookService::queryByPublisher(const string& publisher)
{
    vector<Book> res;
    vector<Book> all = repo.loadAllBooks();
    for (auto& b : all)
    {
        if (b.publisher == publisher)
            res.push_back(b);
    }
    sort(res.begin(), res.end(), [](const Book& a, const Book& b) {
        return a.name < b.name;
    });
    return res;
}

// 获取最新出版前十本图书
vector<Book> BookService::getNewestTop10()
{
    vector<Book> all = repo.loadAllBooks();
    sort(all.begin(), all.end(), Book::cmpByPublishDate);
    vector<Book> top;
    int cnt = 0;
    for (auto& b : all)
    {
        if (cnt >= 10) break;
        top.push_back(b);
        cnt++;
    }
    return top;
}

// 分页获取图书，start下标，count取多少条
vector<Book> BookService::getPageData(const vector<Book>& all, int start, int count)
{
    vector<Book> page;
    int end = start + count;
    for (int i = start; i < end && i < (int)all.size(); i++)
    {
        page.push_back(all[i]);
    }
    return page;
}