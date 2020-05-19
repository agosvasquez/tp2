#include "worker_manager.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cerrno>
#include <iterator>
#include <algorithm>
#include <map>

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
    std::string workers_file = argv[1];
    std::string map_file = argv[2];
    std::string rec = "AgricultoresLeniadoresMineros";
    std::vector<std::string> resourses= {"carbon", "hierro", "madera", "trigo"};
    std::vector<Worker*> prod;
    std::vector<Worker*> recolec;

    typedef struct value_t {
      std::string s;
      int    v;
    }value_t;
    
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
    std::vector<value_t> file;
    while (_workers >> line) {
        size_t found = line.find(equal); 
        if (found == std::string::npos) return -1;
        std::string type = line.substr(0, found);
        std::string _amount = line.substr(found+1);
        int amount = (int) std::stoi(_amount);
        file.push_back({type,amount});
    }
    //CAMBIAR ESTO TIENE QUE SER VARIABLE
    Inventary inv(resourses, 3);
    WorkerManager manager(std::ref(rec),std::ref(prod),std::ref(recolec),inv);
    
	for (int i=0; i<(int)file.size(); ++i) {
		std::string worker_name = file[i].s;
        int amount = file[i].v;
        for (int i = 0; i < amount; i++){
            manager.create_worker(worker_name);
        }
	}
    //PRIMERO CREO LOS PRODUCERS
    for (int i =0; i<(int)prod.size(); i++) {
        prod[i]->start();
    }
    
    for (int i =0; i<(int)recolec.size(); i++) {
        recolec[i]->start();
    }
    
    while (_map >> m){
        manager.save_material(m);
    }
    manager.close();

    for (int i =0 ; i <(int)prod.size(); i++) {
        prod[i]->join();
    }

    for (int i =0 ; i <(int)recolec.size(); i++) {
        recolec[i]->join();
    }

    for (int i =0 ; i <(int)prod.size(); i++) {
        delete prod[i];
    }

    for (int i =0 ; i <(int)recolec.size(); i++) {
        delete recolec[i];
    }

    std::cout << "Recursos restantes" << std::endl;
    std::map<std::string, int> r = inv.resources;
    std::cout <<"  - Trigo: " << r["trigo"] << std::endl;
    std::cout <<"  - Madera: " << r["madera"] << std::endl;
    std::cout <<"  - Carbon: " << r["carbon"] << std::endl;
    std::cout <<"  - Hierro: " << r["hierro"] << std::endl;
    std::cout << "\n";
    std::cout << "Puntos de Beneficio acumulados: "<< manager.sum << std::endl; 
    
    _workers.close();
    _map.close();
    return 0;
} 
    
