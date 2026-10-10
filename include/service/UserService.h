#ifndef LIBRARY_MANAGEMENT_SYSTEM_USERSERVICE_H
#define LIBRARY_MANAGEMENT_SYSTEM_USERSERVICE_H

#include <string>
#include <memory>
#include <vector>
#include "../repository/UserRepository.h"
#include "../entity/User.h"
#include "../entity/Admin.h"
#include "../entity/Reader.h"

class UserService {
private:
    UserRepository& userRepository;

public:
    UserService(UserRepository& userRepository);

    std::shared_ptr<User> login(const std::string& username, const std::string& password);
    bool registerUser(const std::string& username, const std::string& password, const std::string& role); // "Admin" or "Reader"
    std::shared_ptr<User> getUserById(const std::string& id);
    std::vector<std::shared_ptr<User>> getAllUsers();
    bool updateUserPassword(const std::string& id, const std::string& newPassword);
    bool deleteUser(const std::string& id);
};

#endif //LIBRARY_MANAGEMENT_SYSTEM_USERSERVICE_H