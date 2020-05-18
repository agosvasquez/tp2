#include "baker.h"
#include <iostream>
namespace{
    std::map<std::string,int> MATERIALS = {{"trigo",2},{"carbon",1}};
    int POINTS= 2;
}

Baker::Baker(Inventary& i, int&sum, std::mutex& m): Producer(std::ref(MATERIALS),std::ref(POINTS), i, sum, m){}

int Baker::print(){
    std::cout<<"soy baker\n";
    return 0;
}

Baker::~Baker(){}