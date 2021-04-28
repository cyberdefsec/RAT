#include <iostream>
#include <fstream>
#include <string.h>

#include "listdir.h"

bool ListDir::upload(const string &path, uint32_t len, SOCKET s){
    int lenFile = 0;
    char buf[BUFSIZ] = {'\0'};
    std::ofstream out(path, std::ios::app | std::ios::binary);
    if(out.is_open()){
        while(len > 0){
            lenFile = recv(s, buf, BUFSIZ, 0);
            if(lenFile == EOF || lenFile == 0)
                break;
            out << buf;
            len -= lenFile;
        }
        out.close();
    }
}

void ListDir::getLastWriteTime(FILETIME &filetime, char *strtime, DWORD size){
    SYSTEMTIME sysTime, sysLocal;
    FileTimeToSystemTime(&filetime, &sysTime);
    SystemTimeToTzSpecificLocalTime(NULL, &sysTime, &sysLocal);
    snprintf(strtime, size, "%02d.%02d.%d  %02d:%02d", sysLocal.wMonth, sysLocal.wDay, sysLocal.wYear, sysLocal.wHour, sysLocal.wMinute);

}

std::vector<LISTDIR> ListDir::getListDir(const char *path){
    WIN32_FIND_DATAA ls;
    HANDLE handle;
    dir.clear();
    if((handle = FindFirstFile(path, &ls)) != INVALID_HANDLE_VALUE){
        do{
            if(strcmp(ls.cFileName, ".") == 0)
                continue;
            lsDir.attr = ls.dwFileAttributes;
            lsDir.size = (ls.nFileSizeHigh * (MAXDWORD+1)) + ls.nFileSizeLow;
            getLastWriteTime(ls.ftLastWriteTime, lsDir.date, LEN_NAME);
            strcpy(lsDir.name, ls.cFileName);
            dir.push_back(lsDir);
        }while(FindNextFile(handle, &ls));
        FindClose(handle);
    }
    return dir;
}

bool ListDir::createFile(const char *nameFile){
    HANDLE cFile;
    if((cFile = CreateFile(nameFile, GENERIC_READ, 0, nullptr, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, nullptr)) != INVALID_HANDLE_VALUE){
        CloseHandle(cFile);
        return true;
    }
    return false;
}

bool ListDir::removeFile(char *nameFile){
    return DeleteFile(nameFile);
}

bool ListDir::createDir(const char *nameDir){
    return CreateDirectory(nameDir, nullptr);
}

bool ListDir::removeDir(char *nameDir){
    WIN32_FIND_DATAA ls;
    char path[MAX_PATH];
    DWORD attr;
    HANDLE handle;
    strcat(nameDir, "\\*");
    if((handle = FindFirstFile(nameDir, &ls)) != INVALID_HANDLE_VALUE){
        nameDir[strlen(nameDir) - 1] = '\0';
        do{
            if(strcmp(ls.cFileName, ".") == 0 || strcmp(ls.cFileName, "..") == 0)
                continue;
            snprintf(path, MAX_PATH, "%s%s", nameDir, ls.cFileName);
            if(ls.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){
                ls.dwFileAttributes &= ~FILE_ATTRIBUTE_READONLY;
                setAttribute(path, ls.dwFileAttributes);
                removeDir(path);
                RemoveDirectory(path);
            }
            else{
                setAttribute(path, FILE_ATTRIBUTE_NORMAL);
                removeFile(path);
            }
        }while(FindNextFile(handle, &ls));
        FindClose(handle);
        attr = GetFileAttributes(nameDir);
        attr &= ~FILE_ATTRIBUTE_READONLY;
        setAttribute(nameDir, attr);
        if(RemoveDirectory(nameDir))
            return true;
    }
    return false;
}

bool ListDir::renames(char *oldName, char *newName){
    return MoveFile(oldName, newName);
}

bool ListDir::setAttribute(const char *name, DWORD attr){
    return SetFileAttributes(name, attr);
}
