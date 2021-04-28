#ifndef __DISK_H__
#define __DISK_H__

#include <iostream>
#include <vector>

#include "common.h"

class Disk{

public:
    Disk(){}
    ~Disk(){}
    std::vector<LISTDISK> getListDisk();

private:
    std::vector<LISTDISK> listDisk;
    LISTDISK d;
};


#endif // __DISK_H__
