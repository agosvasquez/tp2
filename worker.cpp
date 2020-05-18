#include "worker.h"
#include <iostream>

Worker::Worker(BlockingQueue& queue): q(queue){};

int Worker::print(){
    std::cout << "JEJE";
    return 0;
}