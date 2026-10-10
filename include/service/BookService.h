#ifndef BOOKSERVICE_H
#define BOOKSERVICE_H

#include <vector>
#include <string>
#include "Book.h"
#include "BookRepository.h"
using namespace std;

// 图书业务服务层，处理图书相关全部业务逻辑
class BookService
{
private:
    BookRepository repo;
public:
    const static int PAGE_SIZE;
    // 分页每页数量

    BookService(string filePath);

    // 获取全部图书
    vector<Book> getAllBooks();

    // 添加图书，返回true添加成功
    bool addBook(const Book& book);

    // 根据isbn删除图书
    bool deleteByIsbn(const string& isbn);

    // 根据书名删除图书（匹配第一个）
    bool deleteByName(const string& name);

    // 根据isbn修改图书
    bool modifyByIsbn(const string& oldIsbn, const Book& newBook);

    // 根据书名修改图书（匹配第一个）
    bool modifyByName(const string& oldName, const Book& newBook);

    // 查询：按isbn
    vector<Book> queryByIsbn(const string& isbn);

    // 查询：按书名
    vector<Book> queryByName(const string& name);

    // 查询：按作者，结果按书名字典序排序
    vector<Book> queryByAuthor(const string& author);

    // 查询：按出版社，结果按书名字典序排序
    vector<Book> queryByPublisher(const string& publisher);

    // 获取最新出版前十本图书
    vector<Book> getNewestTop10();

    // 分页获取图书，start下标，count取多少条
    vector<Book> getPageData(const vector<Book>& all, int start, int count);
};

#endif
