#ifndef CARPENTER_H
#define CARPENTER_H
#include "producer.h"

class Carpenter: public Producer{
public:
    Carpenter(Inventary& i, int&sum, std::mutex& m);
    int print();
    ~Carpenter();
};



#endif