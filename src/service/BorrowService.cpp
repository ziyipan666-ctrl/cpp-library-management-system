#include "BorrowService.h"
#include <algorithm>

const int BorrowService::PAGE_SIZE = 10;

// 构造函数，传入借阅记录数据文件路径
BorrowService::BorrowService(string filePath)
    : repo(filePath)
{
}

// 获取全部借阅记录
vector<BorrowRecord> BorrowService::getAllRecords()
{
    return repo.loadAllRecords();
}

// 判断用户是否已经借了这本书还未归还
bool BorrowService::isUserBorrowNotReturn(const string& account, const string& bookIsbn)
{
    vector<BorrowRecord> all = repo.loadAllRecords();
    for (auto& r : all)
    {
        if (r.account == account && r.bookIsbn == bookIsbn && r.returnDate.empty())
        {
            return true;
        }
    }
    return false;
}

// 借阅图书，返回true借阅成功
bool BorrowService::borrowBook(const BorrowRecord& rec)
{
    if(isUserBorrowNotReturn(rec.account, rec.bookIsbn))
    {
        return false;
    }
    vector<BorrowRecord> list = repo.loadAllRecords();
    list.push_back(rec);
    return repo.saveAllRecords(list);
}

// 归还图书，返回true归还成功
bool BorrowService::returnBook(const string& account, const string& bookIsbn, const string& returnDate)
{
    vector<BorrowRecord> list = repo.loadAllRecords();
    for (auto& r : list)
    {
        if (r.account == account && r.bookIsbn == bookIsbn && r.returnDate.empty())
        {
            r.returnDate = returnDate;
            return repo.saveAllRecords(list);
        }
    }
    return false;
}

// 获取借阅次数前十本图书
vector<pair<string, int>> BorrowService::getBorrowCountTop10()
{
    map<string, int> bookCount;
    vector<BorrowRecord> all = repo.loadAllRecords();
    for (auto& r : all)
    {
        bookCount[r.bookName]++;
    }
    vector<pair<string, int>> vec(bookCount.begin(), bookCount.end());
    // 按借阅次数降序
    sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });
    vector<pair<string, int>> top10;
    int cnt = 0;
    for (auto& item : vec)
    {
        if (cnt >= 10) break;
        top10.push_back(item);
        cnt++;
    }
    return top10;
}

// 分页获取借阅记录，start下标，count取多少条
vector<BorrowRecord> BorrowService::getPageData(const vector<BorrowRecord>& all, int start, int count)
{
    vector<BorrowRecord> page;
    if(start < 0) return page;
    int end = start + count;
    for (int i = start; i < end && i < (int)all.size(); i++)
    {
        page.push_back(all[i]);
    }
    return page;
}

// 获取用户借阅记录
vector<BorrowRecord> BorrowService::getMyBorrowRecords(const string& account)
{
    vector<BorrowRecord> all = repo.loadAllRecords();
    vector<BorrowRecord> res;
    for(auto &r : all)
    {
        if(r.account == account)
        {
            res.push_back(r);
        }
    }
    return res;
}

