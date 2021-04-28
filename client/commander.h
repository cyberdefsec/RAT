#ifndef __COMMANDER_H__
#define __COMMANDER_H__

#include <vector>

#include "common.h"
#include "sysinfo.h"
#include "process.h"
#include "disk.h"
#include "listdir.h"
#include "service.h"
#include "shell.h"
#include "users.h"
#include "groups.h"
#include "host.h"

class Commander{

public:
    Commander();
    ~Commander();
    void parserCommand();
    bool initSocket();
    bool connectServer(char* addr, uint16_t port);
    void closeServer();

private:
    bool initWSA();
    Disk disk;
    ListDir listDir;
    Process proc;
    SysInfo sysInfo;
    Shell shell;
    Users users;
    Groups groups;
    Host host;
    Service srv;
    DATA data;
    SYSINFO systemInfo;

    std::string buffer;
    std::vector<NETINFO> netInfo;
    std::vector<LISTDISK> lsDisk;
    std::vector<LISTDIR> lsDir;
    std::vector<LISTPROC> lsProc;
    std::vector<INFOUSER> lsUser;
    std::vector<INFOGROUP> lsGroup;
    std::vector<LISTSERVICE> lsService;

    char *addrSrv = nullptr;
    uint16_t portSrv;
    SOCKET s = 0;
    WSADATA wsdata;
    struct sockaddr_in sin;

    char *arg1 = nullptr;
    char *arg2 = nullptr;
    char *arg3 = nullptr;
};

#endif // __COMMANDER_H__
