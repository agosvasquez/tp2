#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cerrno>
#include <iterator>
#include <algorithm>
#include "blocking_queue.h"
#include "map"
#include "worker_manager.h"
#include "worker.h"

/*class Buffer {
    private:
    char* data;
    public:
    Buffer(int size) {
        this->data = new char[size];
    }
    ~Buffer() {
        delete[] this->data;
    }

};
class File {
    private: 
    FILE * f;
    public:
    File(const char *name, const char *flags) {
        this->f = fopen(name, flags);
        //cambiar!!!
        if (!this->f) std::exception();
    }
    ~File() {
        fclose(this->f);    
    }
    int read(Buffer buff, int size_of, int size){
        return fread(&buff, size_of, size, f);
    }
};
*/

#define MAX = 30;

int main(int argc, char *argv[]) {
    char m;
    std::string line;
    std::string workers_file = argv[1];//trabajadores.cfg
    std::string map_file = argv[2];//mapa.txt

    std::string recolectors = "AgricultoresLeniadoresMineros";

    //std::vector<std::thread> productores(MAX);
    //std::vector<std::thread> consumidores(MAX);

    std::vector<Worker*> workers;
  
    std::cout << "HOLA!\n"; 
    std::ifstream _workers(workers_file,std::ifstream::in);
    if (!_workers){
        std::cerr << "File couldn't be opened!\n"; 
        std::cerr << "Error code: " << std::strerror(errno);
        return -1; }
    std::ifstream _map(map_file, std::ifstream::in);
    if (!_map){
        std::cerr << "File couldn't be opened!\n"; 
        std::cerr << "Error code: " << std::strerror(errno);
        return -1;}
    std::string equal = "="; 
    std::map<std::string,int> file ;
    WorkerManager manager(std::ref(recolectors),std::ref(workers));


    std::cout << "ARCHIVO!\n"; 
    //parseo el archivo
    while ( _workers >> line) {
        size_t found = line.find(equal); 
        if (found == std::string::npos) return -1;
        std::string type = line.substr(0, found);
        std::string _amount = line.substr(found+1);
        int amount = (int) std::stoi(_amount);
        file.insert({type,amount});
        std::cout << "size!\n" << file.size() << std::endl;
    }
    std::cout << "hello!\n";
    std::cout << "size!\n" << file.size() << std::endl; 
    //creo workers
    std::map<std::string, int>::iterator it = file.begin();
	for (;it!=file.end(); ++it) {
		std::string worker_name = it->first;
        int amount = it->second;
        for (int i = 0; i < amount; i++){
            std::cout << "Creating workers: " << i+1 << '\n';
            manager.create_worker(worker_name);
        }
	};
    //std::vector<Worker*>::iterator w_it = workers.begin();
    for (int i =0 ;i <(int)workers.size(); i++) {
        workers[i]->print();
	};

    //leo el mapa y hago las colas
    while (_map >> m ){
        manager.save_material(m);
        /*std::cout <<"agricultor " << manager.agricultor_q.queue.size() << std::endl;
        std::cout <<"leniador " << manager.leniador_q.queue.size() << std::endl;
        std::cout << "miner "<< manager.miner_q.queue.size() << std::endl;
        std::cout << m << std::endl;;*/
    }
    

    _workers.close();
    _map.close();
    return 0;
} 
    
