#include "baker.h"
#include <iostream>
#include <string>
#include <map>
namespace{
    std::map<std::string,int> MAT = {{"trigo",2},{"carbon",1}};
    int POINTS= 5;
}

Baker::Baker(Inventary& i, int&sum, std::mutex& m):
 Producer(std::ref(MAT),std::ref(POINTS), i, sum, m){}

int Baker::print(){
    std::cout<<"soy baker\n";
    return 0;
}

Baker::~Baker(){}
