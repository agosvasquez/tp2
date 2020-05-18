#include "producer.h"
#include <iostream>
#include <unistd.h>

Producer::Producer(std::map<std::string, int>& material, int& points, Inventary& i, int& s, std::mutex& m):
Worker(i), materials(material),points(points),sum(s),mutex(m) {}

void Producer::operator()(){ 
    std::cout << "en producer" << std::endl;
    while(inventary.get_resources(materials)){
        //for (auto& t : inventary.resources)
        /*std::cout << t.first << " " 
                << t.second.first << " " 
                << t.second.second << "\n";*/
        usleep(60000);
        mutex.lock();
        sum += points;
        mutex.unlock();
    }
    
}