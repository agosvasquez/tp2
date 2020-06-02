#include "inventary.h"
#include <iostream>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <thread>

Inventary::Inventary(std::vector<std::string>& materials){
     for (int i =0 ; i <(int)materials.size(); i++) {
        resources.insert({materials[i], 0});
	}
}

Inventary::~Inventary(){}

void Inventary::set_workers(int workers){
    recolectors_working = workers;
}

void Inventary::add(std::string& material){
    std::unique_lock<std::mutex> uniq_l(mut);
    resources[material] ++;
    condition.notify_all();
}


bool Inventary::get_resources(std::map<std::string,int>& recipe){
    std::unique_lock<std::mutex> uniq_l(mut);
    while (!check_completed_recipe(recipe)){
        if (is_finish())return false;
        condition.wait(uniq_l);
    }
    std::map<std::string, int>::iterator it = recipe.begin();
    for (; it!=recipe.end(); ++it) resources[it->first] -= it->second;

    return true;
}


bool Inventary::check_completed_recipe(std::map<std::string,int>& recipe){
    bool aux= true;
    std::map<std::string, int>::iterator it = recipe.begin();
    for (; it!=recipe.end(); ++it) {
        if (resources[it->first] < it->second){ aux=false; break;}
    }
    return aux;
}

void Inventary::update_workers(){
    std::unique_lock<std::mutex> uniq_l(r);
    recolectors_working --;
    if (recolectors_working == 0)condition.notify_all();
}

bool Inventary::is_finish(){
    std::unique_lock<std::mutex> uniq_l(r);
    return recolectors_working == 0;
}

void Inventary::print_inventary(){
    std::cout << "Recursos restantes:" << std::endl;
    std::cout <<"  - Trigo: " << resources["trigo"] << std::endl;
    std::cout <<"  - Madera: " << resources["madera"] << std::endl;
    std::cout <<"  - Carbon: " << resources["carbon"] << std::endl;
    std::cout <<"  - Hierro: " << resources["hierro"] << std::endl;
    std::cout << "\n";
}
