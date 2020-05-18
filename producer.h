#ifndef PRODUCER_H
#define PRODUCER_H
#include "worker.h"
#include <map>

class Producer: public Worker{
private:
    std::map<std::string, int>& materials;
    int& points;
public:
    Producer(std::map<std::string, int>&  materials, int& points, BlockingQueue& q);
};
#endif 