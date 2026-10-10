#ifndef LIBRARY_MANAGEMENT_SYSTEM_USERREPOSITORY_H
#define LIBRARY_MANAGEMENT_SYSTEM_USERREPOSITORY_H

#include <vector>
#include <string>
#include <memory>
#include "../entity/User.h"
#include "../entity/Admin.h"
#include "../entity/Reader.h"

class UserRepository {
private:
    std::string filename;
    std::vector<std::shared_ptr<User>> users;

    void loadUsers();
    void saveUsers();

public:
    UserRepository(const std::string& filename);
    ~UserRepository();

    std::shared_ptr<User> findById(const std::string& id);
    std::shared_ptr<User> findByUsername(const std::string& username);
    void addUser(const std::shared_ptr<User>& user);
    void updateUser(const std::shared_ptr<User>& user); // Update by ID
    void deleteUser(const std::string& id);
    std::vector<std::shared_ptr<User>> getAllUsers() const;
};

#endif //LIBRARY_MANAGEMENT_SYSTEM_USERREPOSITORY_H