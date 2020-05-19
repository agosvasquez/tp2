#ifndef PRODUCER_H
#define PRODUCER_H
#include "worker.h"
#include <string>
#include <map>
#include <mutex>

class Producer: public Worker{
private:
    std::map<std::string, int>& materials;
    int& points;
    int& sum;
    std::mutex& mut;
public:
    Producer(std::map<std::string,int>& mat, int& p,
    Inventary& i,int&sum, std::mutex& m);
    void run();
};
#endif
