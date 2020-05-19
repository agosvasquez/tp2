#include "leniador.h"
#include <iostream>
#include <string>
#include <vector>

namespace{
     std::vector<std::string> MAT = {"madera"};
}
Leniador::Leniador(BlockingQueue& q, Inventary& i):
Recolector(std::ref(MAT),q,i){}

int Leniador::print(){
     std::cout<< "soy leniador\n";
     return 0;
}
