#ifndef RECOLECTOR_H
#define RECOLECTOR_H
#include <string>
#include "worker.h"

class Recolector: public Worker{
public:
Recolector(std::vector<std::string>& material, BlockingQueue& queue);
void operator()();
protected:
std::vector<std::string>& material;
};


#endif