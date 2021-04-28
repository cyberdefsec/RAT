#ifndef __LISTDIR_H__
#define __LISTDIR_H__

#include <vector>

#include "common.h"

class ListDir{

public:
    ListDir(){}
    ~ListDir(){}
    std::vector<LISTDIR> getListDir(const char *path);
    bool createFile(const char *nameFile);
    bool removeFile(char *nameFile);
    bool createDir(const char *nameDir);
    bool removeDir(char *nameDir);
    bool renames(char *oldName, char *newName);
    bool setAttribute(const char *name, DWORD attr);
    bool upload(const string &path, uint32_t len, SOCKET s);
private:
    std::vector<LISTDIR> dir;
    LISTDIR lsDir;
    DATA data;
    void getLastWriteTime(FILETIME &filetime, char *strtime, DWORD size);
};

#endif // __LISTDIR_H__
