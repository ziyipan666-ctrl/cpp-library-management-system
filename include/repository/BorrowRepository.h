#ifndef BORROWREPOSITORY_H
#define BORROWREPOSITORY_H

#include <vector>
#include <string>
#include "BorrowRecord.h"
using namespace std;

// 借阅记录仓库，操作borrow_records.txt
class BorrowRepository
{
private:
    string filePath;
public:
    // 构造函数，传入借阅记录文件路径
    BorrowRepository(string path);

    // 读取全部借还记录
    vector<BorrowRecord> loadAllRecords();

    // 保存全部借还记录
    // recordList 记录集合
    // return true成功 false失败
    bool saveAllRecords(const vector<BorrowRecord>& recordList);
};

#endif
