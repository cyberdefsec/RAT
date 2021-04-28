#ifndef __SYSINFO_H__
#define __SYSINFO_H__

#include <vector>

#include "common.h"

#define WIDTH 7

class SysInfo{

public:
    SysInfo(){}
    ~SysInfo(){}
    SYSINFO getSysInfo();
    std::vector<NETINFO> getNetInfo();
    void getNetStat();

private:
    SYSINFO info;
    NETINFO netInfo;
    std::vector<NETINFO> listNetInfo;
    void getNameOS(char *outName);
    void getProcessor(char *outName, DWORD len);
    void getArchitecture(char *outName, DWORD len);
    void getIpInfo();
};



#endif // __SYSINFO_H__
