#include "FileUtil.h"

// 读取文件所有行
vector<string> FileUtil::readAllLines(const string& filePath)
{
    vector<string> result;
    ifstream fin(filePath);
    if (!fin.is_open())
    {
        return result;
    }
    string line;
    while (getline(fin, line))
    {
        result.push_back(line);
    }
    fin.close();
    return result;
}

// 写入文件所有行
bool FileUtil::writeAllLines(const string& filePath, const vector<string>& lines)
{
    ofstream fout(filePath);
    if (!fout.is_open())
    {
        return false;
    }
    for (const string& s : lines)
    {
        fout << s << endl;
    }
    fout.close();
    return true;
}
