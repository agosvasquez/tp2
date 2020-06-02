#include "worker_manager.h"
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <map>
#include "parser.h"
#include "file.h"

#define MAX = 30;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cout <<"Use ./tp file file" << std::endl;
        return(1);
    }
    char m;
    std::string line;
    std::vector<Worker*> prod,recolec;
    Parser p(std::ref(line));
    File _workers(argv[1]),_map(argv[2]); 
    WorkerManager manager(std::ref(prod),std::ref(recolec));

    manager.create_workers(_workers,p);

    for (int i =0; i<(int)prod.size(); i++) prod[i]->start();
    for (int i =0; i<(int)recolec.size(); i++) recolec[i]->start();
    
    while (_map.read(m)) manager.save_material(std::ref(m));
    manager.close();

    for (int i =0 ; i <(int)recolec.size(); i++) recolec[i]->join();
    for (int i =0 ; i <(int)prod.size(); i++) prod[i]->join();
     
    for (int i =0 ; i <(int)prod.size(); i++) delete prod[i];
    for (int i =0 ; i <(int)recolec.size(); i++) delete recolec[i];
    
    manager.output_result();
    return 0;
} 
    
