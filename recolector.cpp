#include "recolector.h"

Recolector::Recolector(std::vector<std::string>& material, BlockingQueue& queue):Worker(queue),material(material){} 

void Recolector::operator()(){
    std::string material = q.pop();
    
}

