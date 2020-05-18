#include "inventary.h"
#include <iostream>


Inventary::Inventary(std::vector<std::string> materials, int r):recolectors_working(r), completed(false){
     for (int i =0 ;i <(int)materials.size(); i++) {
        resources.insert({materials[i], 0});
	};
}

Inventary::~Inventary(){}

void Inventary::add(std::string material){
    std::unique_lock<std::mutex> uniq_l(mut);
    std::map<std::string, int>::iterator it = resources.find(material); 
    if (it != resources.end())
    it->second +=1; 
    //condition.notify_all();
}


bool Inventary::get_resources(std::map<std::string,int> recipe){
    std::unique_lock<std::mutex> uniq_l(mut);
    check_completed_recipe(recipe);
    while(!completed){
         //no deberia ser necesario;
        if(is_finish())return false;
        //condition.wait(uniq_l);
        check_completed_recipe(recipe); 
    }
    std::map<std::string, int>::iterator it = recipe.begin();
    for (;it!=recipe.end(); ++it) {
        resources[it->first] -= it->second;
    };
    completed = false;
    return true;
}


void Inventary::check_completed_recipe(std::map<std::string,int> recipe){
    bool aux= true;
    std::map<std::string, int>::iterator it = recipe.begin();
    for (;it!=recipe.end(); ++it) {
        if (resources[it->first] < it->second){ aux=false; break;}
    };
    completed = aux;
}

void Inventary::update_workers(){
    std::lock_guard<std::mutex> guard_l(r);
    recolectors_working --;
    std::cout << recolectors_working;
}

bool Inventary::is_finish(){
    std::unique_lock<std::mutex> uniq_l(r);
    return recolectors_working == 0;
}