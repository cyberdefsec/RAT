#include <iostream>
#include <vector>

#include "service.h"
#include "privileges.h"

std::vector<LISTSERVICE> Service::getListService(){
    SC_HANDLE schandle;
    ENUM_SERVICE_STATUS status[BUFSIZ];
    LISTSERVICE srv;
    DWORD size = sizeof(status);
    DWORD needed = 0;
	DWORD outReturn = 0;
	DWORD handle = 0;
	ZeroMemory(&status, BUFSIZ);
	lsService.clear();
    if((schandle = OpenSCManager(nullptr, nullptr, SC_MANAGER_CONNECT | SC_MANAGER_ENUMERATE_SERVICE)) != nullptr){
        EnumServicesStatus(schandle, SERVICE_WIN32, SERVICE_STATE_ALL, (LPENUM_SERVICE_STATUS)&status, size, &needed, &outReturn, &handle);
        for(DWORD i = 0; i < outReturn; i++){
            srv.currentState = status[i].ServiceStatus.dwCurrentState;
            strcpy(srv.serviceName, status[i].lpServiceName);
            strcpy(srv.name, status[i].lpDisplayName);
            lsService.push_back(srv);
        }
    }
    CloseServiceHandle(schandle);
    return lsService;
}
