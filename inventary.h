#ifndef INVENTARY_H
#define INVENTARY_H
#include <string>
#include <condition_variable>
#include <mutex>
#include <vector>
#include <map>

class Inventary{
protected:
    std::mutex mut;
    std::mutex r;
    std::condition_variable condition;
    int recolectors_working;
    bool completed;
    std::map<std::string, int> resources;
public:
    explicit Inventary(std::vector<std::string> materials);
    void add_and_check(std::string material);
    void add(std::string material);
    bool get_resources(std::map<std::string,int> recipe);
    bool check_completed_recipe(std::map<std::string,int> recipe);
    void update_workers();
    bool is_finish();
    void set_workers(int workers);
    void print_inventary();
    ~Inventary();
};

#endif
