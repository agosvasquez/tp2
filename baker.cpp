#include "baker.h"

namespace{
    std::map<std::string,int> MATERIALS = {{"trigo",2},{"carbon",2}};
    int POINTS= 2;
}

Baker::Baker(BlockingQueue& queue): Producer(std::ref(MATERIALS),std::ref(POINTS), queue){}