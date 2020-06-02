#ifndef WORKER_H
#define WORKER_H
#include "thread.h"
class Inventary;

class Worker: public Thread{
protected:
    Inventary& inventary;
public:
    explicit Worker(Inventary& inventary);
    virtual int print();
    virtual void run();
    ~Worker();
};

#endif
