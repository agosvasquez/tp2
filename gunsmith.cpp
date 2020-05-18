#include "gunsmith.h"
#include <iostream>

namespace {
    std::map<std::string,int> MATERIALS = {{"carbon",2},{"hierro",2}};
    int POINTS= 3;
}

Gunsmith::Gunsmith(Inventary& i, int&sum, std::mutex& m): Producer(std::ref(MATERIALS),std::ref(POINTS), i,sum,m){}

int Gunsmith::print(){
    std::cout<<"soy guns\n";
    return 0;
}

Gunsmith::~Gunsmith(){}