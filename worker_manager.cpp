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


WorkerManager::WorkerManager(std::string& names_rec, std::vector< Worker*>& workers, Inventary& i):
names_rec(names_rec), workers(workers),i(i),sum(0){}

void WorkerManager::create_worker(std::string worker_name){
    std::cout<<worker_name << "\n";

    if (names_rec.find(worker_name)!= std::string::npos){
            if (worker_name == AGRICULTORS) workers.push_back(new Agricultor (std::ref(agricultor_q),i));
            else if (worker_name == LENIADORES)workers.push_back(new Leniador(std::ref(leniador_q),i));
            else if (worker_name == MINERS) workers.push_back(new Miner(std::ref(miner_q),i));
            
    }else{
       if (worker_name == BAKERS) workers.push_back(new Baker(i,std::ref(sum),std::ref(m)));
        else if (worker_name == CARPENTERS)workers.push_back(new Carpenter(i,std::ref(sum),std::ref(m)));
        else if (worker_name == GUNSMITHS) workers.push_back(new Gunsmith(i,std::ref(sum),std::ref(m)));
    }
}

int WorkerManager::save_material(char m){
    if (m == 'T') agricultor_q.push("trigo");
    else if (m == 'M') leniador_q.push("madera");
    else if (m == 'H') miner_q.push("hierro");
    else if (m =='C') miner_q.push("carbon");
    else return -1;
    return 0;
}

void WorkerManager::close(){
    agricultor_q.close();
    leniador_q.close();
    miner_q.close();
}