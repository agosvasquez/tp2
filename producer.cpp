#include "producer.h"
#include <iostream>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>

Producer::Producer(std::map<std::string, int>& material, int& points, Inventary& i, int& s, std::mutex& m):
Worker(i), materials(material),points(points),sum(s),mut(m) {}

void Producer::run(){ 
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << " en el producer thread " << this_id << "\n";
    while(inventary.get_resources(materials)){
        std::thread::id this_id = std::this_thread::get_id();
        std::cout << " Generando puntos " << this_id << "\n";
        //for (auto& t : inventary.resources)
        /*std::cout << t.first << " " 
                << t.second.first << " " 
                << t.second.second << "\n";*/
        usleep(60000);
        std::unique_lock<std::mutex> uniq_l(mut);
        std::cout << "Anted de update puntos en el thread " << this_id << " y es  " << sum<< "\n";
        sum += points;
        std::cout << "Despues de update en el thread " << this_id << " y es  " << sum<< "\n";
    }
    
}