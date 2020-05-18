#ifndef WORKER_MANAGER_H
#define WORKER_MANAGER_H
#include "worker.h"
#include "blocking_queue.h"

class WorkerManager{
    private:
    //std::map<std::string,Recolector> recolectors;
    //std::map<std::string,Producer> producers;
    std::string& names_rec;
    std::vector<Worker*>& producers;
    std::vector<Worker*>& recolectors;
    Inventary& i;
    std::mutex m;
    public:
    int sum;
    BlockingQueue agricultor_q;
    BlockingQueue miner_q;
    BlockingQueue leniador_q;
    void create_worker(std::string worker_name);
    WorkerManager(std::string& names_rec, std::vector<Worker*>& p,std::vector<Worker*>& r, Inventary& i);
    int save_material(char m);
    void close();
};

#endif