#ifndef MINER_H
#define MINER_H
#include "recolector.h"

class Miner: public Recolector {
public:
    Miner(BlockingQueue& queue, Inventary& i);
    int print();
};

#endif
