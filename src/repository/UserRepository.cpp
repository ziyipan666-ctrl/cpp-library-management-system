#include "UserRepository.h"
#include "FileUtil.h"
#include "Reader.h"
#include "Admin.h"

UserRepository::UserRepository(const string& filename)
    : filename(filename)
{
    loadUsers();
}

vector<User*> UserRepository::loadAllUsers()
{
    vector<User*> userList;
    vector<string> lines = FileUtil::readAllLines(filename);

    for (const string& line : lines)
    {
        if (line.empty())
            continue;
        // 格式：account,password,role
        size_t pos1 = line.find(",");
        if(pos1 == string::npos) continue;
        string account = line.substr(0, pos1);
        string rest = line.substr(pos1 + 1);

        size_t pos2 = rest.find(",");
        if(pos2 == string::npos) continue;
        string password = rest.substr(0, pos2);
        int role = stoi(rest.substr(pos2 + 1));

        User* u = nullptr;
        if(role == 1)
        {
            u = new Reader(account, password);
        }
        else if(role == 2)
        {
            u = new Admin(account, password);
        }
        if(u != nullptr)
        {
            userList.push_back(u);
        }
    }
    return userList;
}

bool UserRepository::saveAllUsers(const vector<User*>& userList)
{
    vector<string> lines;
    for (User* u : userList)
    {
        lines.push_back(u->toString());
    }
    // 第一个参数是成员变量 filename，第二个是组装好的lines
    return FileUtil::writeAllLines(filename, lines);
}



UserRepository::~UserRepository()
{
    saveUsers();
}

void UserRepository::loadUsers()
{
    // 兼容旧Service接口，数据读取由loadAllUsers完成
}

void UserRepository::saveUsers()
{
    // 数据已经由saveAllUsers直接写文件
}
