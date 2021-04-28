#include <iostream>

#include "sysinfo.h"

void SysInfo::getNameOS(char *outName){
    if(!IsWindows10OrGreater())
        strcpy(outName, "Windows 10");
    else if (IsWindows8OrGreater())
        strcpy(outName, "Windows 8");
    else if(IsWindows8Point1OrGreater())
        strcpy(outName, "Windows 8.1");
    else if(IsWindows7OrGreater())
        strcpy(outName, "Windows 7");
    else if(IsWindows7SP1OrGreater())
        strcpy(outName, "Windows 7 SP1");
    else if(IsWindowsVistaOrGreater())
        strcpy(outName, "Windows Vista");
    else if(IsWindowsVistaSP1OrGreater())
        strcpy(outName, "Windows Vista SP1");
    else if(IsWindowsVistaSP2OrGreater())
        strcpy(outName, "Windows Vista SP2");
    else if(IsWindowsXPOrGreater())
        strcpy(outName, "Windows XP");
    else if(IsWindowsXPSP1OrGreater())
        strcpy(outName, "Windows XP SP1");
    else if(IsWindowsXPSP2OrGreater())
        strcpy(outName, "Windows XP SP2");
    else if(IsWindowsXPSP3OrGreater())
        strcpy(outName, "Windows XP SP3");
    else
        strcpy(outName, "Windows unknown");
}

void SysInfo::getProcessor(char *outName, DWORD len){
    HKEY key = nullptr;
    DWORD type = 0;
    char buf[LEN_NAME];
    if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &key) == ERROR_SUCCESS){
        if(RegQueryValueEx(key, TEXT("ProcessorNameString"), nullptr, &type, (LPBYTE)&buf, &len) == ERROR_SUCCESS){
            RegCloseKey(key);
            strcpy(outName, buf);
        }
    }
}

void SysInfo::getArchitecture(char *outName, DWORD len){
    HKEY key = nullptr;
    DWORD type = 0;
    char buf[LEN_NAME];
    if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &key) == ERROR_SUCCESS){
        if(RegQueryValueEx(key, TEXT("Identifier"), nullptr, &type, (LPBYTE)&buf, &len) == ERROR_SUCCESS){
            RegCloseKey(key);
            strcpy(outName, buf);
        }
        else
            printf("Query %ld\n", GetLastError());
    }
    else
        printf("Open %ld\n", GetLastError());
}

void SysInfo::getIpInfo(){
    PIP_ADAPTER_INFO adapterInfo, adapter;
    ULONG buffer = sizeof(IP_ADAPTER_INFO);
    listNetInfo.clear();
    GetAdaptersInfo(nullptr, &buffer);
    if((adapterInfo = (IP_ADAPTER_INFO*)malloc(buffer)) != nullptr){
        if(GetAdaptersInfo(adapterInfo, &buffer) == NO_ERROR){
            adapter = adapterInfo;
            while(adapter){
                strcpy(netInfo.device, adapter->Description);
                strcpy(netInfo.ipaddr, adapter->IpAddressList.IpAddress.String);
                strcpy(netInfo.gateway, adapter->GatewayList.IpAddress.String);
                strcpy(netInfo.dhcp, adapter->DhcpServer.IpAddress.String);
                strcpy(netInfo.mask, adapter->IpAddressList.IpMask.String);
                snprintf(netInfo.mac, LEN_MAC, "%02X:%02X:%02X:%02X:%02X:%02X", adapter->Address[0], adapter->Address[1], adapter->Address[2], adapter->Address[3], adapter->Address[4], adapter->Address[5]);
                if(adapter->DhcpEnabled)
                    netInfo.isDhcp = true;
                else
                    netInfo.isDhcp = false;
                adapter = adapter->Next;
                listNetInfo.push_back(netInfo);
            }
        }
        free(adapterInfo);
    }
}

std::vector<NETINFO> SysInfo::getNetInfo(){
    getIpInfo();
    return listNetInfo;
}


SYSINFO SysInfo::getSysInfo(){
    DWORD len = LEN_NAME;
    memset(&info, '\0', sizeof(info));
    GetUserName(info.currUser, &len);
    len = LEN_NAME;
    GetComputerNameEx(ComputerNameDnsDomain, info.domainName, &len);
    len = LEN_NAME;
    GetComputerName(info.hostName, &len);
    getNameOS(info.nameOS);
    GetSystemDirectory(info.sysDir, LEN_NAME);
    GetWindowsDirectory(info.winDir, LEN_NAME);
    getProcessor(info.processor, LEN_NAME);
    getArchitecture(info.architecture, LEN_NAME);
    info.w = GetSystemMetrics(SM_CXSCREEN);
    info.h = GetSystemMetrics(SM_CYSCREEN);
    return info;
}
