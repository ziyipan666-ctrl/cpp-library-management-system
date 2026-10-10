#include "BookRepository.h"
#include "FileUtil.h"
#include <sstream>

// 构造函数：头文件成员名叫 filename，这里初始化列表必须对应
BookRepository::BookRepository(const string& filename)
    : filename(filename)
{
    loadBooks(); // 构造时自动加载磁盘数据到内存缓存
}

// 析构函数，销毁前把内存数据写入文件
BookRepository::~BookRepository()
{
    saveBooks();
}

// 【私有】从文件加载图书，存入内存vector<shared_ptr<Book>>
void BookRepository::loadBooks()
{
    books.clear();
    vector<string> lines = FileUtil::readAllLines(filename);
    for (const string& line : lines)
    {
        if (line.empty()) continue;

        // 分割逗号：isbn,name,author,publisher,publishDate,price
        size_t pos1 = line.find(",");
        if(pos1 == string::npos) continue;
        string isbn = line.substr(0, pos1);
        string rest = line.substr(pos1 + 1);

        size_t pos2 = rest.find(",");
        if(pos2 == string::npos) continue;
        string name = rest.substr(0, pos2);
        rest = rest.substr(pos2 + 1);

        size_t pos3 = rest.find(",");
        if(pos3 == string::npos) continue;
        string author = rest.substr(0, pos3);
        rest = rest.substr(pos3 + 1);

        size_t pos4 = rest.find(",");
        if(pos4 == string::npos) continue;
        string publisher = rest.substr(0, pos4);
        rest = rest.substr(pos4 + 1);

        size_t pos5 = rest.find(",");
        if(pos5 == string::npos) continue;
        string publishDate = rest.substr(0, pos5);
        string price = rest.substr(pos5 + 1);

        // 新建智能指针对象，放入缓存
        shared_ptr<Book> book = make_shared<Book>(isbn, name, author, publisher, publishDate, price);
        books.push_back(book);
    }
}

//【私有】把内存缓存的books写入txt文件
void BookRepository::saveBooks()
{
    vector<string> lines;
    for (const auto& b : books)
    {
        lines.push_back(b->toString());
    }
    FileUtil::writeAllLines(filename, lines);
}

// 获取全部图书（返回shared_ptr数组，和头文件签名一致）
vector<shared_ptr<Book>> BookRepository::getAllBooks() const
{
    return books;
}

// 根据ID查找图书
shared_ptr<Book> BookRepository::findById(const string& id)
{
    for (const auto& b : books)
    {
        if (b->getId() == id)
        {
            return b;
        }
    }
    return nullptr;
}

// 根据ISBN查找图书
shared_ptr<Book> BookRepository::findByIsbn(const string& isbn)
{
    for (const auto& b : books)
    {
        if (b->getIsbn() == isbn)
        {
            return b;
        }
    }
    return nullptr;
}

// 按书名模糊查找
vector<shared_ptr<Book>> BookRepository::findByTitle(const string& title)
{
    vector<shared_ptr<Book>> res;
    for (const auto& b : books)
    {
        if (b->getTitle().find(title) != string::npos)
        {
            res.push_back(b);
        }
    }
    return res;
}

// 按作者查找
vector<shared_ptr<Book>> BookRepository::findByAuthor(const string& author)
{
    vector<shared_ptr<Book>> res;
    for (const auto& b : books)
    {
        if (b->getAuthor().find(author) != string::npos)
        {
            res.push_back(b);
        }
    }
    return res;
}

// 添加图书
void BookRepository::addBook(const shared_ptr<Book>& book)
{
    books.push_back(book);
    saveBooks();
}

// 更新图书
void BookRepository::updateBook(const shared_ptr<Book>& book)
{
    for (auto& b : books)
    {
        if (b->getId() == book->getId())
        {
            b = book;
            saveBooks();
            return;
        }
    }
}

// 删除图书
void BookRepository::deleteBook(const string& id)
{
    for (auto it = books.begin(); it != books.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            books.erase(it);
            saveBooks();
            return;
        }
    }
}


vector<Book> BookRepository::loadAllBooks()
{
    vector<Book> result;
    for (auto &b : books)
    {
        result.push_back(*b);
    }
    return result;
}

bool BookRepository::saveAllBooks(const vector<Book>& list)
{
    books.clear();
    for (const auto& b : list)
    {
        books.push_back(make_shared<Book>(b));
    }
    saveBooks();
    return true;
}
