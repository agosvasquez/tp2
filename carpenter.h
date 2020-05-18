#ifndef CARPENTER_H
#define CARPENTER_H
#include "producer.h"

class Carpenter: public Producer{
public:
    Carpenter(BlockingQueue& queue);
    ~Carpenter();
};



#endif