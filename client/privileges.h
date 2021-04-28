#ifndef __PRIVILEGES_H__
#define __PRIVILEGES_H__

#include "common.h"

class Privileges{

public:
    Privileges(){}
    ~Privileges(){}
    bool setDebugPriv();
    bool setBackupPriv();
    bool setShutdownPriv();
    bool setTcbPriv();
    bool setOwnershipPriv();
    bool setSecurityPriv();

};

#endif // __PRIVILEGES_H__
