#ifndef __PROCESS_H__
#define __PROCESS_H__

#include <vector>

#include "common.h"

class Process{

public:
    Process(){}
    ~Process(){}
    std::vector<LISTPROC> getListProcess();
    bool createProcess(char *nameProc, bool hide = false);
    bool killProcess(const char *nameProc);

private:
    std::vector<LISTPROC> proc;
};

#endif // __LISTPROC_H__
