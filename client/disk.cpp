#include "disk.h"


std::vector<LISTDISK> Disk::getListDisk(){
    char disks[LEN_NAME];
    char *disk = nullptr;
    GetLogicalDriveStrings(LEN_NAME, disks);
    disk = disks;
    listDisk.clear();
    while(*disk){
        d.type = GetDriveType(disk);
        sprintf(d.disk, "%s", disk);
        GetDiskFreeSpaceEx(disk, nullptr, &d.totalSpace, nullptr);
        listDisk.push_back(d);
        disk = disk + strlen(disk) + 1;
    }
    return listDisk;
}
