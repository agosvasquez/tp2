#include "miner.h"
#include <iostream>
#include <string>
#include <vector>

namespace{
    std::vector<std::string> MAT{"hierro", "carbon"};
}

Miner::Miner(BlockingQueue& q, Inventary& i):Recolector(std::ref(MAT), q, i){}

int Miner::print(){
    std::cout << "Soy minero\n";
    return 0;
}
