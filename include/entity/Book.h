#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

using namespace std;

// 图书类，用于存储图书信息并提供相关操作
class Book
{
public:
    string isbn;            // ISBN图书编码（国际标准书号）
    string name;            // 图书名称
    string author;          // 作者
    string publisher;       // 出版社
    string publishDate;     // 出版日期
    string price;           // 价格

    // Book构造函数，带默认参数，可无参构造
    Book(string isbn="", string name="", string author="",
         string publisher="", string publishDate="", string price="");


    string getId() const { return isbn; }
    string getIsbn() const { return isbn; }
    string getTitle() const { return name; }
    string getAuthor() const { return author; }

    // 打印当前图书的全部信息到控制台
    void printInfo() const;// const修饰，不会修改对象成员

    // 将图书信息拼接为一个字符串返回，返回包含图书所有字段的字符串
    string toString() const;

    // 静态比较函数：按出版日期比较两本书
    // a：图书对象a
    // b：图书对象b
    // 如果a的出版日期早于b，返回true；否则false
    // 静态成员，可直接用于sort排序
    static bool cmpByPublishDate(const Book& a, const Book& b);
};

#endif


