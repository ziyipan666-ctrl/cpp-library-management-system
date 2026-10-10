#ifndef LIBRARY_MANAGEMENT_SYSTEM_USER_H
#define LIBRARY_MANAGEMENT_SYSTEM_USER_H

#include <string>

class User {
protected:
    std::string id;
    std::string username;
    std::string password;

public:
    User(const std::string& id, const std::string& username, const std::string& password);
    virtual ~User() = default; // Virtual destructor for base class

    std::string getId() const;
    std::string getUsername() const;
    std::string getPassword() const;

    void setPassword(const std::string& password);
};

#endif //LIBRARY_MANAGEMENT_SYSTEM_USER_H