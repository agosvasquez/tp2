#include "carpenter.h"

namespace{
    std::map<std::string, int> MATERIALS= {{"madera",3},{"hierro",2}};
    int POINTS = 5;
}

Carpenter::Carpenter(BlockingQueue& queue): Producer(std::ref(MATERIALS), std::ref(POINTS),queue){}