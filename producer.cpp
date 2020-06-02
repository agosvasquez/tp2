#include "producer.h"
#include <iostream>
#include <unistd.h>
#include <stdint.h>
#include <sys/types.h>

Producer::Producer(std::map<std::string, int>& material, int& points,
Inventary& i, int& s, std::mutex& m):
Worker(i), materials(material),points(points),sum(s),mut(m) {}

void Producer::run(){ 
    while (inventary.get_resources(std::ref(materials))){
        usleep(60000);
        std::unique_lock<std::mutex> uniq_l(mut);
        sum += points;
    }
}
