#include <iostream>
#include <windows.h>
#include <lmaccess.h>
#include <lm.h>
#include <stdlib.h>
#include <sddl.h>

#include "users.h"

bool Users::createUser(const std::string nameUser, const std::string passwd){
    USER_INFO_2 info;
    DWORD paramErr = 0;
    int len = 0;
    NET_API_STATUS status = 0;
    memset(&info, '\0', sizeof(info));
    info.usri2_priv = USER_PRIV_USER;
    info.usri2_flags = UF_SCRIPT | UF_NORMAL_ACCOUNT | UF_DONT_EXPIRE_PASSWD;
    info.usri2_acct_expires = TIMEQ_FOREVER;
    /*Set user name */
    len = MultiByteToWideChar(CP_ACP, 0, nameUser.c_str(), -1, nullptr, 0);
    info.usri2_name = new WCHAR[len];
    MultiByteToWideChar(CP_ACP, 0, nameUser.c_str(), -1, info.usri2_name, len);
    /*Set password */
    len = MultiByteToWideChar(CP_ACP, 0, passwd.c_str(), -1, nullptr, 0);
    info.usri2_password = new WCHAR[len];
    MultiByteToWideChar(CP_ACP, 0, passwd.c_str(), -1, info.usri2_password, len);
    status = NetUserAdd(nullptr, 2, (LPBYTE)&info, &paramErr);
    delete[] info.usri2_name;
    delete[] info.usri2_password;
    if(status == NERR_Success)
        return true;
    return false;
}

bool Users::removeUser(const std::string nameUser){
    WCHAR name[LEN_NAME];
    MultiByteToWideChar(CP_ACP, 0, nameUser.c_str(), -1, name, LEN_NAME);
    if(NetUserDel(nullptr, name) == NERR_Success)
        return true;
    return false;
}

std::vector<INFOUSER> Users::listUsers(VOID){
    LPUSER_INFO_1 info = nullptr;
    LPUSER_INFO_23 sid = nullptr;
    DWORD outRead, totalEntry, resume;
    LPSTR strSid;
    INFOUSER usr;
    listUser.clear();
    outRead = totalEntry = resume = 0;
    if(NetUserEnum(nullptr, 1, FILTER_NORMAL_ACCOUNT, (LPBYTE*)&info, MAX_PREFERRED_LENGTH, &outRead, &totalEntry, &resume) == NERR_Success){
        for(DWORD count = 0; count < outRead; count++){
            WideCharToMultiByte(CP_ACP, 0, info->usri1_name, -1, usr.nameUser, LEN_NAME, nullptr, nullptr);
            WideCharToMultiByte(CP_ACP, 0, info->usri1_comment, -1, usr.comment, LEN_NAME, nullptr, nullptr);
            if(info->usri1_flags & UF_ACCOUNTDISABLE)
                usr.block = TRUE;
            else
                usr.block = FALSE;
            NetUserGetInfo(nullptr, info->usri1_name, 23, (LPBYTE*)&sid);
            ConvertSidToStringSid(sid->usri23_user_sid, &strSid);
            strncpy(usr.sid, strSid, LEN_NAME);
            LocalFree(strSid);
            listUser.push_back(usr);
            info++;
        }
    }
    return listUser;
}

bool Users::changePassword(const std::string nameUser, const std::string oldPasswd, const std::string newPasswd){
    WCHAR name[LEN_NAME];
    WCHAR oldPass[LEN_NAME];
    WCHAR newPass[LEN_NAME];
    MultiByteToWideChar(CP_ACP, 0, nameUser.c_str(), -1, name, LEN_NAME);
    MultiByteToWideChar(CP_ACP, 0, oldPasswd.c_str(), -1, oldPass, LEN_NAME);
    MultiByteToWideChar(CP_ACP, 0, newPasswd.c_str(), -1, newPass, LEN_NAME);
    if(NetUserChangePassword(nullptr, name, oldPass, newPass) == NERR_Success)
        return true;
    return false;
}

bool Users::blockUser(const std::string &nameUser){
    WCHAR name[LEN_NAME];
    USER_INFO_1 *info = nullptr;
    MultiByteToWideChar(CP_ACP, 0, nameUser.c_str(), -1, name, LEN_NAME);
    if(NetUserGetInfo(nullptr, name, 1, (LPBYTE*)&info) == NERR_Success){
        if(info->usri1_flags & UF_ACCOUNTDISABLE)
            info->usri1_flags &= ~UF_ACCOUNTDISABLE | UF_PASSWORD_EXPIRED;
        else
            info->usri1_flags |= UF_ACCOUNTDISABLE | UF_DONT_EXPIRE_PASSWD;
        if(NetUserSetInfo(nullptr, name, 1, (LPBYTE)info, nullptr) == NERR_Success){
            NetApiBufferFree(info);
            return true;
        }
    }
    return false;
}
