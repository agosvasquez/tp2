#ifndef GUNSMITH_H
#define GUNSMITH_H
#include "producer.h"

class Gunsmith: public Producer{
public:
    Gunsmith(BlockingQueue& queue);
    ~Gunsmith();
};



#endif