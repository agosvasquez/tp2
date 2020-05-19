#ifndef BAKER_H
#define BAKER_H
#include "producer.h"

class Baker: public Producer{
public:
    Baker(Inventary& i, int&sum, std::mutex& m);
    int print();
    ~Baker();
};

#endif
