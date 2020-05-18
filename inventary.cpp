#include "inventary.h"


Inventary::Inventary(std::vector<std::string> materials, int r):recolectors_working(r), completed(false){
     for (int i =0 ;i <(int)materials.size(); i++) {
        resources.insert({materials[i], 0});
	};
}

void Inventary::add(std::string material){
    std::unique_lock<std::mutex> uniq_l(mut);
    std::map<std::string, int>::iterator it = resources.find(material); 
    if (it != resources.end())
    it->second +=1;
}

void Inventary::add_and_check(std::string material){
    add(material);
    std::unique_lock<std::mutex> uniq_l(mut);
    check_completed_recipe();
    if (completed) condition.notify_all();
}

void Inventary::get_resources(std::string material){
    std::unique_lock<std::mutex> uniq_l(mut);
    while(recolectors_working > 0){
        while(!completed){
            condition.wait(uniq_l);
        }
        int pos =check_completed_recipe(); 
        std::map<std::string, int>::iterator it = recipes[pos].begin();
        for (;it!=recipes[pos].end(); ++it) {
            resources[it->first] -= it->second;
        };
    }
}

void Inventary::set_need_resources(std::map<std::string,int>& recipe){
    std::lock_guard<std::mutex> guard_l(m);
    recipes.push_back(recipe);
}

int Inventary::check_completed_recipe(){
    if (recipes.size() == 0) return -1;
    bool aux= true;
    int i;
    for (i =0 ;i <(int)recipes.size(); i++) {
       std::map<std::string, int> map = recipes[i];
       std::map<std::string, int>::iterator it = map.begin();
       for (;it!=map.end(); ++it) {
           if (resources[it->first] < it->second){ aux=false; break;}
       };
       if (aux)break;
	};
    completed = aux;
    return i;
}

void Inventary::update_workers(){
    
}