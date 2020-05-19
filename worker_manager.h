#ifndef WORKER_MANAGER_H
#define WORKER_MANAGER_H
#include "worker.h"
#include "blocking_queue.h"
#include "parser.h"
#include "file.h"
#include <string>
#include <vector>

class WorkerManager{
    private:
    std::string& names_rec;
    std::vector<Worker*>& producers;
    std::vector<Worker*>& recolectors;
    Inventary& i;
    std::mutex m;
    public:
    int sum;
    BlockingQueue agri_q;
    BlockingQueue miner_q;
    BlockingQueue leniador_q;
    void create_worker(std::string worker_name);
    WorkerManager(std::vector<Worker*>&p,std::vector<Worker*>& r,Inventary& i);
    int save_material(char m);
    void close();
    void print_workers_points();
    void create_workers(File& workers, Parser& parser);
};

#endif
