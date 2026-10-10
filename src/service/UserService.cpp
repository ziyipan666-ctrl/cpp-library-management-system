#include "UserService.h"
#include "Reader.h"
#include "Admin.h"
#include "BorrowRecord.h"

const int UserService::PAGE_SIZE = 5;

// 构造函数，传入用户、借阅文件路径
UserService::UserService(string userFilePath, string borrowFilePath)
    : repo(userFilePath), borrowRepo(borrowFilePath)
{
}

// 填充用户借阅记录
void UserService::fillBorrowHistory(User* user)
{
    vector<BorrowRecord> allRecords = borrowRepo.loadAllRecords();
    for (const BorrowRecord& r : allRecords)
    {
        if (r.account == user->account)
        {
            user->borrowHistory.push_back(r);
        }
    }
}

// 获取所有用户
vector<User*> UserService::getAllUsers()
{
    return repo.loadAllUsers();
}

// 账号是否已经存在
bool UserService::isAccountExist(const string& account)
{
    vector<User*> list = repo.loadAllUsers();
    for (auto* u : list)
    {
        if (u->account == account)
            return true;
    }
    return false;
}

// 注册读者账号
bool UserService::registerReader(const string& account, const string& password)
{
    if (isAccountExist(account))
        return false;
    vector<User*> list = repo.loadAllUsers();
    User* u = new Reader(account, password);
    list.push_back(u);
    return repo.saveAllUsers(list);
}

// 新增用户
bool UserService::addUser(const string& account, const string& password, int role)
{
    if (isAccountExist(account))
        return false;
    vector<User*> list = repo.loadAllUsers();
    User* u = nullptr;
    if (role == 1)
    {
        u = new Reader(account, password);
    }
    else if (role == 2)
    {
        u = new Admin(account, password);
    }
    if (u == nullptr)
        return false;
    list.push_back(u);
    return repo.saveAllUsers(list);
}

// 删除用户
bool UserService::deleteUserByAccount(const string& account)
{
    vector<User*> list = repo.loadAllUsers();
    for (auto it = list.begin(); it != list.end(); ++it)
    {
        if ((*it)->account == account)
        {
            delete *it;       //释放堆内存，防止内存泄漏
            list.erase(it);
            return repo.saveAllUsers(list);
        }
    }
    return false;
}

// 修改密码
bool UserService::modifyPassword(const string& account, const string& newPwd)
{
    vector<User*> list = repo.loadAllUsers();
    for (auto* u : list)
    {
        if (u->account == account)
        {
            u->password = newPwd;
            return repo.saveAllUsers(list);
        }
    }
    return false;
}

// 查询用户
vector<User*> UserService::queryByAccount(const string& account)
{
    vector<User*> res;
    vector<User*> all = repo.loadAllUsers();
    for (auto* u : all)
    {
        if (u->account == account)
        {
            fillBorrowHistory(u);
            res.push_back(u);
        }
    }
    return res;
}

// 登录检查
User* UserService::loginCheck(const string& account, const string& password, int role)
{
    vector<User*> all = repo.loadAllUsers();
    for (auto* u : all)
    {
        if (u->account == account && u->password == password && u->role == role)
        {
            return u; //直接返回仓库加载出来的对象指针，不再用static临时对象，修复野指针BUG
        }
    }
    return nullptr;
}

// 删除自己
bool UserService::deleteSelf(const string& account)
{
    return deleteUserByAccount(account);
}

// 给指定账号追加借书记录
bool UserService::appendBorrowRecord(const string& account, const BorrowRecord& br)
{
    vector<User*> list = repo.loadAllUsers();
    for (auto* u : list)
    {
        if (u->account == account)
        {
            u->borrowHistory.push_back(br);
            return repo.saveAllUsers(list);
        }
    }
    return false;
}

// 还书：不新增记录，找到原有借书记录，填充returnDate
bool UserService::appendReturnRecord(const string& account, const BorrowRecord& br)
{
    vector<User*> list = repo.loadAllUsers();
    for (auto* u : list)
    {
        if (u->account == account)
        {
            //遍历该用户的借阅记录，匹配账号+ISBN，修改归还日期
            for(auto& rec : u->borrowHistory)
            {
                if(rec.account == account && rec.bookIsbn == br.bookIsbn && rec.returnDate.empty())
                {
                    rec.returnDate = br.returnDate;
                    return repo.saveAllUsers(list);
                }
            }
        }
    }
    return false;
}

// 分页获取用户列表，start下标，count取多少条
vector<User*> UserService::getPageData(const vector<User*>& all, int start, int count)
{
    vector<User*> page;
    if(start < 0) return page;
    int end = start + count;
    for (int i = start; i < end && i < (int)all.size(); i++)
    {
        page.push_back(all[i]);
    }
    return page;
}