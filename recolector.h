#ifndef RECOLECTOR_H
#define RECOLECTOR_H
#include "worker.h"
#include <string>
#include <vector>

class BlockingQueue;

class Recolector: public Worker{
public:
    Recolector(std::vector<std::string>& m, BlockingQueue& q, Inventary& i);
    void run();
protected:
    std::vector<std::string>& material;
    BlockingQueue& q;
};

#endif
