#ifndef __GROUPS_H__
#define __GROUPS_H__

#include <vector>
#include "common.h"

class Groups{

public:
    Groups(){}
    ~Groups(){}
    bool createGroup(const std::string &nameGroup);
    bool removeGroup(const std::string &nameGroup);
    bool addUserGroup(const std::string &nameUser, const std::string &nameGroup);
    std::vector<INFOGROUP> listGroups();
private:
    std::vector<INFOGROUP> listGroup;
};

#endif
