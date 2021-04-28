#include <iostream>

#include "commander.h"
#include "host.h"

int main(){
    Commander cmd;
    Host hst;
    bool isConnect = false;
    setlocale(LC_ALL, "rus");
    while(true){
        do{
            isConnect = cmd.connectServer("127.0.0.1", 2035);
        }while(isConnect == false);
        cmd.parserCommand();
        cmd.initSocket();
    }
    return 0;
}
