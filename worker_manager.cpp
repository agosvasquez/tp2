#include "worker_manager.h"
#include "agricultor.h"
#include "baker.h"
#include "miner.h"
#include "leniador.h"
#include "carpenter.h"
#include "gunsmith.h"
#include <iostream>

namespace {
    std::string AGRICULTORS = "Agricultores";
    std::string LENIADORES = "Leniadores";
    std::string MINERS = "Mineros";
    std::string BAKERS = "Cocineros";
    std::string CARPENTERS = "Carpinteros";
    std::string GUNSMITHS = "Armeros";
}


WorkerManager::WorkerManager(std::string& names_rec, std::vector< Worker*>& workers):names_rec(names_rec), workers(workers){}

void WorkerManager::create_worker(std::string worker_name){
    if (names_rec.find(worker_name)!= std::string::npos){
            if (worker_name == AGRICULTORS) workers.push_back(new Agricultor (std::ref(agricultor_q)));
            else if (worker_name == LENIADORES)workers.push_back(new Leniador(std::ref(leniador_q)));
            else if (worker_name == MINERS) workers.push_back(new Miner(std::ref(miner_q)));
            
    } 
    
}

int WorkerManager::save_material(char m){
    if (m == 'T') agricultor_q.push("T");
    else if (m == 'M') leniador_q.push("M");
    else if (m == 'H') miner_q.push("H");
    else if (m =='C') miner_q.push("C");
    else return -1;
    return 0;
}