#include <iostream>
#include <stdbool.h>

#include "process.h"
#include "privileges.h"


std::vector<LISTPROC> Process::getListProcess(){
    PROCESSENTRY32 p;
    LISTPROC listProc;
    HANDLE handle, hproc;
    proc.clear();
    handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    p.dwSize = sizeof(PROCESSENTRY32);
    Process32First(handle, &p);
    do{
        ZeroMemory(&listProc, sizeof(listProc));
        if((hproc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, false, p.th32ProcessID)) != nullptr)
            GetModuleFileNameEx(hproc, nullptr, listProc.path, sizeof(listProc.path));
        strcpy(listProc.name, p.szExeFile);
        listProc.pid = p.th32ProcessID;
        listProc.ppid = p.th32ParentProcessID;
        proc.push_back(listProc);
        CloseHandle(hproc);
    }while(Process32Next(handle, &p));
    CloseHandle(handle);
    return proc;
}

bool Process::createProcess(char *nameProc, bool hide){
    STARTUPINFO sinfo;
    PROCESS_INFORMATION pinfo;
    memset(&sinfo, 0, sizeof(sinfo));
    if(hide == true){
        sinfo.dwFlags = STARTF_USESHOWWINDOW;
        sinfo.wShowWindow = SW_HIDE;
    }
    sinfo.cb = sizeof(sinfo);
    return CreateProcess(nullptr, nameProc, nullptr, nullptr, FALSE, CREATE_NEW_CONSOLE, nullptr, nullptr, &sinfo, &pinfo);
}

bool Process::killProcess(const char *nameProc){
    HANDLE handle;
    std::vector<LISTPROC> list = getListProcess();
    for(size_t count = 0; count < list.size(); count++){
        if(strcmp(list[count].name, nameProc) == 0){
            if((handle = OpenProcess(PROCESS_ALL_ACCESS, false, list[count].pid)) != INVALID_HANDLE_VALUE){
                if(TerminateProcess(handle, 0)){
                    CloseHandle(handle);
                    return true;
                }
                CloseHandle(handle);
            }
        }
    }
    return false;
}
