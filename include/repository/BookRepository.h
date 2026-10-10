#ifndef LIBRARY_MANAGEMENT_SYSTEM_BOOKREPOSITORY_H
#define LIBRARY_MANAGEMENT_SYSTEM_BOOKREPOSITORY_H

#include <vector>
#include <string>
#include <memory>
#include "../entity/Book.h"
using namespace std;

class BookRepository {
private:
    
    // 图书数据文件路径
    string filename;
    // 内存中缓存的图书数据
    vector<shared_ptr<Book>> books;

    // 加载图书数据到内存
    void loadBooks();
    // 保存内存中的图书数据到文件
    void saveBooks();

public:
    //  构造函数，传入图书数据文件路径
    BookRepository(const string& filename);
    // 析构函数，保存图书数据到文件
    ~BookRepository();

    shared_ptr<Book> findById(const string& id);// 根据ID查找图书
    shared_ptr<Book> findByIsbn(const string& isbn);// 根据ISBN查找图书
    vector<shared_ptr<Book>> findByTitle(const string& title);// 根据书名查找图书
    vector<shared_ptr<Book>> findByAuthor(const string& author);// 根据作者查找图书
    void addBook(const  shared_ptr<Book>& book);// 新增图书
    void updateBook(const shared_ptr<Book>& book); // 更新图书信息
    void deleteBook(const string& id);// 根据ID删除图书
    vector<shared_ptr<Book>> getAllBooks() const;// 获取所有图书

    // Service层兼容接口
    vector<Book> loadAllBooks();
    bool saveAllBooks(const vector<Book>& list);
};

#endif