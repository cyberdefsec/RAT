#ifndef __USERS_H__
#define __USERS_H__

#include <windows.h>
#include <vector>
#include "common.h"

class Users{

public:
    Users(){}
    ~Users(){}
    bool createUser(const std::string nameUser, const std::string passwd);
    bool removeUser(const std::string nameUser);
    std::vector<INFOUSER> listUsers();
    bool changePassword(const std::string nameUser, const std::string oldPasswd, const std::string newPasswd);
    bool blockUser(const std::string &nameUser);
private:
    std::vector<INFOUSER> listUser;
};

#endif // __USERS_H__
