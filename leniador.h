#ifndef LENIADOR_H
#define LENIADOR_H
#include "recolector.h"

class Leniador: public Recolector{
public:
    Leniador(BlockingQueue& queue, Inventary& i);
    int print();
};



#endif