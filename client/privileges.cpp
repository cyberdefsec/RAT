#include "privileges.h"
#include <iostream>

bool Privileges::setDebugPriv(){
    HANDLE handle;
    LUID debugValue;
    TOKEN_PRIVILEGES tpriv;
    if(OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &handle)){
        if(LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &debugValue)){
            tpriv.PrivilegeCount = 1;
            tpriv.Privileges[0].Luid = debugValue;
            tpriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
            if(AdjustTokenPrivileges(handle, false, &tpriv, sizeof(tpriv), NULL, NULL)){
                CloseHandle(handle);
                return true;
            }
            else
                std::cout << GetLastError() << std::endl;
        }
        else
            std::cout << GetLastError() << std::endl;
        CloseHandle(handle);
    }
    else
        std::cout << GetLastError() << std::endl;
    return false;
}

bool Privileges::setBackupPriv(){
    HANDLE handle;
    unsigned char buf[sizeof(TOKEN_PRIVILEGES) * 2];
    TOKEN_PRIVILEGES &tpriv = *((TOKEN_PRIVILEGES*)buf);
    if(OpenProcessToken( GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &handle)){
        if(LookupPrivilegeValue( NULL, SE_BACKUP_NAME, &tpriv.Privileges[0].Luid)){
            if(LookupPrivilegeValue( NULL, SE_RESTORE_NAME, &tpriv.Privileges[1].Luid)){
                tpriv.PrivilegeCount = 2;
                tpriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
                tpriv.Privileges[1].Attributes = SE_PRIVILEGE_ENABLED;
                if(AdjustTokenPrivileges(handle, FALSE, &tpriv, sizeof(tpriv), NULL, NULL)){
                    CloseHandle(handle);
                    return true;
                }
            }
        }
        CloseHandle(handle);
    }
    return false;
}

bool Privileges::setShutdownPriv(){
    HANDLE handle;
    LUID shutdownVal;
    TOKEN_PRIVILEGES tpriv;
    if(OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &handle)){
        if(LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &shutdownVal)){
            tpriv.PrivilegeCount = 1;
            tpriv.Privileges[0].Luid = shutdownVal;
            tpriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
            if(AdjustTokenPrivileges(handle, false, &tpriv, sizeof(tpriv), NULL, NULL)){
                CloseHandle(handle);
                return true;
            }
        }
        CloseHandle(handle);
    }
    return false;
}

bool Privileges::setTcbPriv(){
    HANDLE handle;
    LUID tcbVal;
    TOKEN_PRIVILEGES tpriv;
    if(OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &handle)){
        if(LookupPrivilegeValue(NULL, SE_TCB_NAME, &tcbVal)){
            tpriv.PrivilegeCount = 1;
            tpriv.Privileges[0].Luid = tcbVal;
            tpriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
            if(AdjustTokenPrivileges(handle, false, &tpriv, sizeof(tpriv), NULL, NULL)){
                CloseHandle(handle);
                return true;
            }
        }
        CloseHandle(handle);
    }
    return false;
}

bool Privileges::setOwnershipPriv(){
    HANDLE handle;
    LUID ownerVal;
    TOKEN_PRIVILEGES tpriv;
    if(OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &handle)){
        if(LookupPrivilegeValue(NULL, SE_TAKE_OWNERSHIP_NAME, &ownerVal)){
            tpriv.PrivilegeCount = 1;
            tpriv.Privileges[0].Luid = ownerVal;
            tpriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
            if(AdjustTokenPrivileges(handle, false, &tpriv, sizeof(tpriv), NULL, NULL)){
                CloseHandle(handle);
                return true;
            }
        }
        CloseHandle(handle);
    }
    return false;
}

bool Privileges::setSecurityPriv(){
    HANDLE handle;
    LUID securityVal;
    TOKEN_PRIVILEGES tpriv;
    if(OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &handle)){
        if(LookupPrivilegeValue(NULL, SE_SECURITY_NAME, &securityVal)){
            tpriv.PrivilegeCount = 1;
            tpriv.Privileges[0].Luid = securityVal;
            tpriv.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
            if(AdjustTokenPrivileges(handle, false, &tpriv, sizeof(tpriv), NULL, NULL)){
                CloseHandle(handle);
                return true;
            }
        }
        CloseHandle(handle);
    }
    return false;
}
