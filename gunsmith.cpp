#include "gunsmith.h"

namespace {
    std::map<std::string,int> MATERIALS = {{"carbon",2},{"hierro",2}};
    int POINTS= 2;
}

Gunsmith::Gunsmith(BlockingQueue& queue): Producer(std::ref(MATERIALS),std::ref(POINTS), queue){}