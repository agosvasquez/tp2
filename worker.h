#ifndef WORKER_H
#define WORKER_H
#include "blocking_queue.h"

class Worker{
protected:
    BlockingQueue& q;

public:
    Worker(BlockingQueue& queue);
    virtual int print();
    //~Worker();

};

#endif