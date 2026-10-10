#ifndef LIBRARY_MANAGEMENT_SYSTEM_ADMIN_H
#define LIBRARY_MANAGEMENT_SYSTEM_ADMIN_H

#include "User.h"

class Admin : public User {
public:
    Admin(const std::string& id, const std::string& username, const std::string& password);
};

#endif //LIBRARY_MANAGEMENT_SYSTEM_ADMIN_H