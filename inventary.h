#ifndef INVENTARY_H
#define INVENTARY_H
#include <map>
#include <string>
#include <condition_variable>
#include <mutex>
#include <vector>
#include <map>
#include "recolector.h"

class Inventary{
private:
    std::map<std::string, int> resources;
    std::mutex mut;
    std::mutex m;
    std::mutex r;
    std::condition_variable condition;
    std::vector<std::map<std::string,int>&> recipes;
    int recolectors_working;
    bool completed;
public:
    Inventary(std::vector<std::string> materials, int recolectors);
    void add_and_check(std::string material);
    void add(std::string material);
    void get_resources(std::string material);
    void set_need_resources(std::map<std::string,int>& recipe);
    int check_completed_recipe();
    void update_workers();
    ~Inventary();
};


#endif