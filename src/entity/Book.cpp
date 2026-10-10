#include "Book.h"

// Book类实现文件，定义了Book类的成员函数
Book::Book(string isbn, string name, string author,
           string publisher, string publishDate, string price)
    :isbn(isbn), name(name), author(author), publisher(publisher),
     publishDate(publishDate), price(price)
{
}

// 打印图书信息
void Book::printInfo() const
{
    cout << "ISBN: " << isbn << endl;
    cout << "书名: " << name << endl;
    cout << "作者: " << author << endl;
    cout << "出版社: " << publisher << endl;
    cout << "出版时间: " << publishDate << endl;
    cout << "价格: " << price << endl;
}

// 将图书信息转为逗号分隔字符串
string Book::toString() const
{
    return isbn + "," + name + "," + author + "," + publisher + "," + publishDate + "," + price;
}

// 按出版日期降序比较图书
bool Book::cmpByPublishDate(const Book& a, const Book& b)
{
    return a.publishDate > b.publishDate;
}
