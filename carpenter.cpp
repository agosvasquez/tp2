#include "carpenter.h"
#include <iostream>
#include <string>
#include <map>

namespace{
    std::map<std::string, int> MATERIALS= {{"madera",3},{"hierro",1}};
    int POINTS = 2;
}

Carpenter::Carpenter(Inventary& i, int& sum, std::mutex& m):
Producer(std::ref(MATERIALS), std::ref(POINTS),i, sum, m){}

int Carpenter::print(){
    std::cout<<"soy carpenter\n";
    return 0;
}

Carpenter::~Carpenter(){}
