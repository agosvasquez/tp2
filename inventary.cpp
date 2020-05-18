#include "inventary.h"
#include <iostream>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <thread>

Inventary::Inventary(std::vector<std::string> materials, int r):recolectors_working(r), completed(false){
     for (int i =0 ;i <(int)materials.size(); i++) {
        resources.insert({materials[i], 0});
	};
}

Inventary::~Inventary(){}

void Inventary::add(std::string material){
    std::unique_lock<std::mutex> uniq_l(mut);
    std::thread::id this_id = std::this_thread::get_id();
    //std::cout << " Guardando en inventario " << this_id << "\n";
    resources[material] ++;
    std::cout <<"AGREGO " << material << "\n";
    std::cout << "despierto a todos \n";
    std::cout << "Quedan "<<recolectors_working << " working" "\n";
    condition.notify_all();
}


bool Inventary::get_resources(std::map<std::string,int> recipe){
    std::unique_lock<std::mutex> uniq_l(mut);
    std::thread::id this_id = std::this_thread::get_id();
    //std::cout << "Evaluo si get resources en el thread " << this_id << " y es  " << completed<< "\n";
    while(!check_completed_recipe(recipe)){
        if(is_finish())return false;
        //std::cout << "WAITING " << this_id << "\n";
        condition.wait(uniq_l);
        std::cout << " AWAKE " << this_id << "\n";
        //std::cout << "Evaluo si get resources en el thread " << this_id << " y es  " << completed<< "\n";
    }
    std::map<std::string, int>::iterator it = recipe.begin();
    for (;it!=recipe.end(); ++it) {
        resources[it->first] -= it->second;
    };
    return true;
}


bool Inventary::check_completed_recipe(std::map<std::string,int> recipe){
    bool aux= true;
    std::map<std::string, int>::iterator it = recipe.begin();
    for (;it!=recipe.end(); ++it) {
        if (resources[it->first] < it->second){ 
            std::thread::id this_id = std::this_thread::get_id();
            std::cout << "Resour madera " << resources["madera"] << "\n";
            std::cout << "Resour carbon " << resources["carbon"] << "\n";
            std::cout << "Resour hierro " << resources["hierro"] << "\n";
            std::cout << "Resour trigo " << resources["trigo"] << "\n";
            std::cout << " Check resour " << it->first << " " << resources[it->first] << " en rec " << it->second<< "\n";
            aux=false;
            break;
        }
    };
    return aux;
}

void Inventary::update_workers(){
    std::unique_lock<std::mutex> uniq_l(r);
    if(recolectors_working >0)recolectors_working --;
    std::thread::id this_id = std::this_thread::get_id();
}

bool Inventary::is_finish(){
    std::unique_lock<std::mutex> uniq_l(r);
    return recolectors_working == 0;
}