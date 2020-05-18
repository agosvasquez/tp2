#include "agricultor.h"
#include <iostream>
namespace{
    std::vector<std::string> MATERIAL = {"trigo"};
}
Agricultor::Agricultor(BlockingQueue& queue): Recolector(std::ref(MATERIAL),queue){}

int Agricultor::print(){
    std::cout<<"soy agricultor\n";
    return 0;
}