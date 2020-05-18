#ifndef RECOLECTOR_H
#define RECOLECTOR_H
#include "worker.h"
#include "blocking_queue.h"


class Recolector: public Worker{
public:
Recolector(std::vector<std::string>& material, BlockingQueue& queue, Inventary& i);
void operator()();
protected:
std::vector<std::string>& material;
BlockingQueue& q;
};


#endif