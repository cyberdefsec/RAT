#include <iostream>
#include <windows.h>
#include <lmaccess.h>
#include <lm.h>
#include <stdlib.h>
#include <sddl.h>
#include <locale>

#include "groups.h"

bool Groups::createGroup(const std::string &nameGroup){
    LOCALGROUP_INFO_1 grp;
    DWORD len = 0;
    memset(&grp, '\0', sizeof(grp));
    len = MultiByteToWideChar(CP_UTF8, 0, nameGroup.c_str(), -1, nullptr, 0);
    grp.lgrpi1_name = new WCHAR[len];
    MultiByteToWideChar(CP_ACP, 0, nameGroup.c_str(), -1, grp.lgrpi1_name, len);
    if(NetLocalGroupAdd(nullptr, 1, (LPBYTE)&grp, nullptr) == NERR_Success){
        delete[] grp.lgrpi1_name;
        return true;
    }
    delete[] grp.lgrpi1_name;
    return false;
}

bool Groups::removeGroup(const std::string &nameGroup){
    WCHAR name[LEN_NAME];
    MultiByteToWideChar(CP_ACP, 0, nameGroup.c_str(), -1, name, LEN_NAME);
    if(NetLocalGroupDel(nullptr, name) == NERR_Success)
        return true;
    return false;
}

std::vector<INFOGROUP> Groups::listGroups(){
    LOCALGROUP_INFO_1 *lstGrp = nullptr;
    DWORD outRead = 0;
    DWORD totalEntry = 0;
    PDWORD_PTR resume = nullptr;
    INFOGROUP grp;
    listGroup.clear();
    if(NetLocalGroupEnum(nullptr, 1, (LPBYTE*)&lstGrp, MAX_PREFERRED_LENGTH, &outRead, &totalEntry, resume) == NERR_Success){
        for(DWORD count = 0; count < outRead; count++){
            WideCharToMultiByte(CP_ACP, 0, lstGrp->lgrpi1_name, -1, grp.nameGroup, LEN_NAME, nullptr, nullptr);
            WideCharToMultiByte(CP_ACP, 0, lstGrp->lgrpi1_comment, -1, grp.comment, LEN_NAME, nullptr, nullptr);
            listGroup.push_back(grp);
            lstGrp++;
        }
    }
    return listGroup;
}

bool Groups::addUserGroup(const std::string &nameUser, const std::string &nameGroup){
    LOCALGROUP_MEMBERS_INFO_3 loclGrp;
    DWORD lenUsr, lenGrp, err;
    WCHAR namegrp[LEN_NAME];
    lenUsr = lenGrp = err = 0;
    lenUsr = MultiByteToWideChar(CP_ACP, 0, nameUser.c_str(), -1, nullptr, 0);
    loclGrp.lgrmi3_domainandname = new WCHAR[lenUsr];
    MultiByteToWideChar(CP_ACP, 0, nameUser.c_str(), -1, loclGrp.lgrmi3_domainandname, lenUsr);
    MultiByteToWideChar(CP_ACP, 0, nameGroup.c_str(), -1, namegrp, LEN_NAME);
    err = NetLocalGroupAddMembers(nullptr, namegrp, 3, (LPBYTE)&loclGrp, 1);
    delete[] loclGrp.lgrmi3_domainandname;
    if(err == NERR_Success)
        return true;
    return false;
}
