#ifndef BAKER_H
#define BAKER_H
#include "producer.h"

class Baker: public Producer{
public:
    Baker(BlockingQueue&);
    ~Baker();
};


#endif