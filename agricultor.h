#ifndef AGRICULTOR_H
#define AGRICULTOR_H
#include "recolector.h"


class Agricultor : public Recolector{
public:
    Agricultor(BlockingQueue& queue,Inventary& i);
    int print();
};

#endif