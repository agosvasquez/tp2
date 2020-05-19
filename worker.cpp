#include "worker.h"
#include <iostream>

Worker::Worker(Inventary& invent): inventary(invent){}

int Worker::print(){
    return 0;
}

void Worker::run() {}

Worker::~Worker(){}
