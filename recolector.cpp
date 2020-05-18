#include "recolector.h"
#include <iostream>
#include <unistd.h>

Recolector::Recolector(std::vector<std::string>& material, BlockingQueue& queue, Inventary& i):
Worker(i),material(material),q(queue){} 

void Recolector::operator()(){
    while(1){
        std::cout << "en recolecotr" << std::endl;
        std::string material = q.pop();
        if (material.empty()) {inventary.update_workers();return;}
        usleep(50000);
        inventary.add(material);
    }
}

