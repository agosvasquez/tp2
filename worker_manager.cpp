#include "worker_manager.h"
#include "agricultor.h"
#include "baker.h"
#include "miner.h"
#include "leniador.h"
#include "carpenter.h"
#include "gunsmith.h"
#include "inventary.h"
#include "parser.h"
#include "value.h"
#include <iostream>

namespace {
    std::string AGRICULTORS = "Agricultores";
    std::string LENIADORES = "Leniadores";
    std::string MINERS = "Mineros";
    std::string BAKERS = "Cocineros";
    std::string CARPENTERS = "Carpinteros";
    std::string GUNSMITHS = "Armeros";
    std::string REC = "AgricultoresLeniadoresMineros";
    std::vector<std::string> RESOURSES= {"carbon", "hierro", "madera", "trigo"};
}

WorkerManager::WorkerManager
(std::vector< Worker*>& p,std::vector< Worker*>& r):
names_rec(REC), producers(p), recolectors(r),sum(0){
    i = new Inventary (RESOURSES);
}

WorkerManager::~WorkerManager(){
    delete i;
}

void WorkerManager::create_worker(std::string& worker_name){
    Inventary& inv =*i; 
    if (names_rec.find(worker_name)!= std::string::npos){
            if (worker_name == AGRICULTORS) 
                recolectors.push_back(new Agricultor(std::ref(agri_q),inv));
            else if (worker_name == LENIADORES)
                recolectors.push_back(new Leniador(std::ref(leniador_q),inv));
            else if (worker_name == MINERS) 
                recolectors.push_back(new Miner(std::ref(miner_q),inv));
    }else{
        if (worker_name == BAKERS) 
            producers.push_back(new Baker(inv,std::ref(sum),m));
        else if (worker_name == CARPENTERS)
            producers.push_back(new Carpenter(inv,std::ref(sum),m));
        else if (worker_name == GUNSMITHS) 
            producers.push_back(new Gunsmith(inv,std::ref(sum),m));
    }
}

int WorkerManager::save_material(char& m){
    if (m == 'T') agri_q.push(std::ref(RESOURSES[3]));
    else if (m == 'M') leniador_q.push(std::ref(RESOURSES[2]));
    else if (m == 'H') miner_q.push(std::ref(RESOURSES[1]));
    else if (m =='C') miner_q.push(std::ref(RESOURSES[0]));
    else 
        return 1;
    return 0;
}

void WorkerManager::close(){
    agri_q.close();
    leniador_q.close();
    miner_q.close();
}

void WorkerManager::output_result(){
    i->print_inventary();
    std::cout << "Puntos de Beneficio acumulados: "<< sum << std::endl; 
}

void WorkerManager::create_workers(File& workers, Parser& parser){
    std::vector<value_t> parsed;
    parser.parse_workers(workers,parsed);
	for (int i=0; i<(int)parsed.size(); ++i) {
		std::string worker_name = parsed[i].s;
        int amount = parsed[i].v;
        for (int i = 0; i < amount; i++){
           create_worker(worker_name);
        }
	}
    i->set_workers((int)recolectors.size());
}
