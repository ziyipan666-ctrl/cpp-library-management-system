#include "BorrowRepository.h"
#include "FileUtil.h"

// 构造函数，传入借阅记录文件路径
BorrowRepository::BorrowRepository(string path)
    : filePath(path)
{
}

// 读取全部借还记录
vector<BorrowRecord> BorrowRepository::loadAllRecords()
{
    vector<BorrowRecord> recList;
    vector<string> lines = FileUtil::readAllLines(filePath);

    for (const string& line : lines)
    {
        if (line.empty())
            continue;
        // account,bookIsbn,bookName,borrowDate,returnDate
        size_t pos1 = line.find(",");
        if(pos1 == string::npos) continue;
        string acc = line.substr(0, pos1);
        string rest = line.substr(pos1 + 1);

        size_t pos2 = rest.find(",");
        if(pos2 == string::npos) continue;
        string isbn = rest.substr(0, pos2);
        rest = rest.substr(pos2 + 1);

        size_t pos3 = rest.find(",");
        if(pos3 == string::npos) continue;
        string bkName = rest.substr(0, pos3);
        rest = rest.substr(pos3 + 1);

        size_t pos4 = rest.find(",");
        if(pos4 == string::npos) continue;
        string bDate = rest.substr(0, pos4);
        string rDate = rest.substr(pos4 + 1);

        BorrowRecord br(acc, isbn, bkName, bDate, rDate);
        recList.push_back(br);
    }
    return recList;
}

// 保存全部借还记录
bool BorrowRepository::saveAllRecords(const vector<BorrowRecord>& recordList)
{
    vector<string> lines;
    for (const BorrowRecord& r : recordList)
    {
        lines.push_back(r.toString());
    }
    return FileUtil::writeAllLines(filePath, lines);
}
