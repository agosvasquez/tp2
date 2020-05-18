#ifndef WORKER_H
#define WORKER_H
#include "inventary.h"

class Worker{
protected:
    Inventary& inventary;
public:
    Worker(Inventary& inventary);
    virtual int print();
    virtual void operator()();
    ~Worker();

};

#endif