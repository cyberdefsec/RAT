#ifndef __SERVICE_H__
#define __SERVICE_H__

#include <vector>

#include "common.h"

class Service{

public:
    Service(){}
    ~Service(){}
    std::vector<LISTSERVICE> getListService();
private:
    std::vector<LISTSERVICE> lsService;
};

#endif // __SERVICE_H__
