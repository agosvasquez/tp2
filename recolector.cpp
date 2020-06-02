#include "recolector.h"
#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include <sys/types.h>

Recolector::Recolector
(std::vector<std::string>& material, BlockingQueue& queue, Inventary& i):
Worker(i),material(material),q(queue){} 

void Recolector::run(){
    while (1){
        std::string material = q.pop();
        usleep(50000);
        if (material.empty()) { inventary.update_workers(); return;}
        inventary.add(std::ref(material));
    }
}

