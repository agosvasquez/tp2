#include "leniador.h"
#include <iostream>

namespace{
     std::vector<std::string> MATERIAL = {"madera"};
}
Leniador::Leniador(BlockingQueue& queue): Recolector(std::ref(MATERIAL), queue){}

int Leniador::print(){
     std::cout<< "soy leniador\n";
     return 0;
}