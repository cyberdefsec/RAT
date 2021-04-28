#ifndef __SHELL_H__
#define __SHELL_H__

#include <stdio.h>
#include <stdlib.h>

#include "common.h"

class Shell{

public:
    Shell(){}
    ~Shell(){}
    void remoteShell(char *cmd, SOCKET s);
private:
    int changeDir(char *path);
};

#endif // __SHELL_H__
