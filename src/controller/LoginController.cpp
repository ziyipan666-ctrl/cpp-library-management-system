#include "../../../include/controller/LoginController.h"

LoginController::LoginController(UserService& us)
    : userService(us)
{
}

std::shared_ptr<User> LoginController::doLogin(const std::string& username, const std::string& password, const std::string& role)
{
    // The UserService::login method checks username and password.
    // The role check might be handled at a higher level (e.g., in MainMenu or specific role menus)
    // or within the login method if different login logic applies to different roles.
    // For now, I'll pass the role to login and let UserService handle it if needed.
    std::shared_ptr<User> user = userService.login(username, password);
    if (user) {
        // Basic role check after successful login
        if (role == "Admin" && std::dynamic_pointer_cast<Admin>(user)) {
            return user;
        } else if (role == "Reader" && std::dynamic_pointer_cast<Reader>(user)) {
            return user;
        }
    }
    return nullptr;
}

bool LoginController::doRegisterReader(const std::string& username, const std::string& password)
{
    return userService.registerUser(username, password, "Reader");
}