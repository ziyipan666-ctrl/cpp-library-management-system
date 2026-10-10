#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <fstream>
#include <vector>
#include <string>
using namespace std;

// 文件工具类，封装文本文件读写操作
namespace FileUtil
{
    // 读取文本文件全部行
    // filePath 文件路径
    // return 每一行字符串组成的vector，打开失败返回空vector
    vector<string> readAllLines(const string& filePath);

    // 将字符串vector全部写入文本，覆盖原有内容
    // filePath 文件路径
    // lines 待写入的行集合
    // return true写入成功，false写入失败
    bool writeAllLines(const string& filePath, const vector<string>& lines);
}

#endif
