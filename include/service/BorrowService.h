#ifndef BORROWSERVICE_H
#define BORROWSERVICE_H

#include <vector>
#include <string>
#include <map>
#include "BorrowRecord.h"
#include "BorrowRepository.h"
using namespace std;

/**
 * @brief 借阅业务服务：借书、还书、借阅排行榜、分页
 */
class BorrowService
{
private:
    BorrowRepository repo;
public:
    const static int PAGE_SIZE;

    BorrowService(string filePath);

    vector<BorrowRecord> getAllRecords();

    // 判断用户是否已经借了这本书还未归还
    bool isUserBorrowNotReturn(const string& account, const string& bookIsbn);

    // 新增一条借书记录
    bool borrowBook(const BorrowRecord& rec);

    // 用户还书：匹配账号+isbn，填充returnDate
    bool returnBook(const string& account, const string& bookIsbn, const string& returnDate);

    // 获取借阅次数Top10，key:书名 value:借阅次数
    vector<pair<string, int>> getBorrowCountTop10();

    vector<BorrowRecord> getMyBorrowRecords(const string& account);
    
    vector<BorrowRecord> getPageData(const vector<BorrowRecord>& all, int start, int count);
};


#endif
