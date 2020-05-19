#ifndef RECOLECTOR_H
#define RECOLECTOR_H
#include "worker.h"
#include "blocking_queue.h"
#include <string>
#include <vector>

class Recolector: public Worker{
public:
    Recolector(std::vector<std::string>& m, BlockingQueue& q, Inventary& i);
    void run();
protected:
    std::vector<std::string>& material;
    BlockingQueue& q;
};

#endif
