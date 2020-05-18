#ifndef GUNSMITH_H
#define GUNSMITH_H
#include "producer.h"

class Gunsmith: public Producer{
public:
    Gunsmith(Inventary& i, int&sum, std::mutex& m);
    int print();
    ~Gunsmith();
};

#endif