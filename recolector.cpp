#include "recolector.h"
#include <iostream>
#include <unistd.h>
#include <sys/types.h>

Recolector::Recolector(std::vector<std::string>& material, BlockingQueue& queue, Inventary& i):
Worker(i),material(material),q(queue){} 

void Recolector::run(){
    while(1){
        std::thread::id this_id = std::this_thread::get_id();
        //std::cout << " en el recolector thread " << this_id << "\n";
        std::string material = q.pop();
        usleep(50000);
        if (material.empty()) {
            //std::cout << " Cola cerrada thread " << this_id << "\n";
            inventary.update_workers();
            return;
            }
        inventary.add(material);
    }
}

