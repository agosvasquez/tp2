#include "worker.h"
#include <iostream>

Worker::Worker(Inventary& invent): inventary(invent){};

int Worker::print(){
    std::cout << "JEJE";
    return 0;
}

void Worker::operator()() {}

Worker::~Worker(){}