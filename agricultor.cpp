#include "agricultor.h"
#include <iostream>
#include <string>
#include <vector>

namespace{
    std::vector<std::string> MATERIAL = {"trigo"};
}
Agricultor::Agricultor(BlockingQueue& queue, Inventary& i):
Recolector(std::ref(MATERIAL),queue, i){}

int Agricultor::print(){
    std::cout<<"soy agricultor\n";
    return 0;
}
