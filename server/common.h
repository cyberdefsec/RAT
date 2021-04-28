#ifndef __COMMON_H__
#define __COMMON_H__

#include <windows.h>
#include <stdbool.h>
#include <versionhelpers.h>
#include <iphlpapi.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <winsvc.h>
#include <wchar.h>

#define LEN_NAME 512
#define LEN_IPADDR 16
#define LEN_MAC 18
#define LEN_DATA 1024

typedef struct{
    int w;
    int h;
    char hostName[LEN_NAME];
    char domainName[LEN_NAME];
    char currUser[LEN_NAME];
    char nameOS[LEN_NAME];
    char sysDir[LEN_NAME];
    char winDir[LEN_NAME];
    char processor[LEN_NAME];
    char architecture[LEN_NAME];
}SYSINFO;

typedef struct{
    char device[LEN_NAME];
    char mac[LEN_MAC];
    char ipaddr[LEN_IPADDR];
    char mask[LEN_IPADDR];
    char gateway[LEN_IPADDR];
    char dhcp[LEN_IPADDR];
    bool isDhcp;
}NETINFO;

typedef struct{
    char name[LEN_NAME];
    char path[LEN_NAME];
    DWORD pid;
    DWORD ppid;

}LISTPROC;

typedef struct{
    char disk[4];
    UINT type;
    ULARGE_INTEGER freeSpace;
    ULARGE_INTEGER totalSpace;
    ULARGE_INTEGER totalFreeSpace;
}LISTDISK;

typedef struct{
    bool block;
    char sid[LEN_NAME];
    char nameUser[LEN_NAME];
    char comment[LEN_NAME];
}INFOUSER;

typedef struct{
    char nameGroup[LEN_NAME];
    char comment[LEN_NAME];
}INFOGROUP;

typedef struct{
    DWORD currentState;
    char name[LEN_NAME];
    char serviceName[LEN_NAME];
}LISTSERVICE;

typedef struct{
    char name[LEN_NAME];
    DWORD attr;
    DWORD size;
    char date[LEN_NAME];
}LISTDIR;

typedef enum{
    SYS = 1, // system information
    SYSNET, // network information
    DISK, // list disk and information disk
    LSDIR, // list directory
    RMDIR, // remove directory
    RMFILE, // remove file
    CRFILE, // create file
    CRDIR, // create dirictory
    RNAME, // rename file or dirictory
    ATTR, // set attribute
    LSPROC, // list process
    CRPROC, // create process
    KILLP, // kill process
    SHELL, // remote shell run
    REBOOT, // reboot system
    POWEROFF, // shutdown system
    LOGONOFF, // user logonoff
    SCREEN, // screenshot
    DOWNLOAD, // download file or dirictory
    UPLOAD, // upload file or dirictory
    LSUSR, // list users
    CRUSR, // create user
    RMUSR, // remove user
    BLCKUSR, // blocking user or unblocking user
    PASSUSR, // change password user
    LSGRP, // list groups
    CRGRP, // create group
    RMGRP, // remove group
    ADDUSRGRP, // add user group
    LSSRV, // list service
    CLBUF  // Clipboard
}COMMANDS;

typedef struct{
    COMMANDS cmd;
    DWORD err;
    DWORD other;
    char data[LEN_DATA];
}DATA;

#endif // __COMMON_H__
