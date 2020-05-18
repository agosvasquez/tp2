#include "miner.h"
#include <iostream>

namespace{
    std::vector<std::string> MATERIAL{"hierro", "carbon"};
}

Miner::Miner(BlockingQueue& queue, Inventary& i):Recolector(std::ref(MATERIAL), queue, i){}

int Miner::print(){
    std::cout << "Soy minero\n";
    return 0;
}