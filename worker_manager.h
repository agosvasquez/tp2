#ifndef WORKER_MANAGER_H
#define WORKER_MANAGER_H
#include "blocking_queue.h"
#include <string>
#include <vector>
#include "worker.h"
class File;
class Parser;
class Inventary;

//se encarga de orquestar la creacion y admisistracion 
//de los recursos usados por los workers
class WorkerManager{
    private:
    std::string& names_rec;
    std::vector<Worker*>& producers;
    std::vector<Worker*>& recolectors;
    Inventary* i;
    std::mutex m;
    int sum;
    BlockingQueue agri_q;
    BlockingQueue miner_q;
    BlockingQueue leniador_q;
    public:
    void create_worker(std::string& worker_name);
    WorkerManager(std::vector<Worker*>&p,std::vector<Worker*>& r);
    //guarda un material m en eñ inventatio
    int save_material(char& m);
    // hace que todas las colas se cierren
    void close();
    void output_result();
    void create_workers(File& workers, Parser& parser);
    ~WorkerManager();
};

#endif
