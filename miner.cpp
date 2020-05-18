#include "miner.h"
#include <iostream>

namespace{
    std::vector<std::string> MATERIAL{"hierro", "carbon"};
}

Miner::Miner(BlockingQueue& queue):Recolector(std::ref(MATERIAL), queue){}

int Miner::print(){
    std::cout << "Soy minero\n";
    return 0;
}