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

    std::string _recolectors = "AgricultoresLeniadoresMineros";
    std::vector<std::string> resourses= {"carbon", "hierro", "madera", "trigo"};

    //std::vector<std::thread> productores(MAX);
    //std::vector<std::thread> consumidores(MAX);

    std::vector<Worker*> producers;
    std::vector<Worker*> recolectors;

    typedef struct value_t {
      std::string s;
      int    v;
    }value_t;
    
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
    std::vector<value_t> file ;
    std::cout << "ARCHIVO!\n"; 
    //parseo el archivo
    while ( _workers >> line) {
        size_t found = line.find(equal); 
        if (found == std::string::npos) return -1;
        std::string type = line.substr(0, found);
        std::string _amount = line.substr(found+1);
        int amount = (int) std::stoi(_amount);
        file.push_back({type,amount});
        //std::cout << "size!\n" << file.size() << std::endl;
    }
    //CAMBIAR ESTO TIENE QUE SER VARIABLE
    Inventary inventary(resourses, 3);
    WorkerManager manager(std::ref(_recolectors),std::ref(producers),std::ref(recolectors) ,inventary);
    

    //std::cout << "hello!\n";
    //std::cout << "size!\n" << file.size() << std::endl; 
    //creo workers

	for (int i=0; i<(int)file.size(); ++i) {
		std::string worker_name = file[i].s;
        int amount = file[i].v;
        for (int i = 0; i < amount; i++){
            //std::cout << "Creating workers: " << i+1 << '\n';
            manager.create_worker(worker_name);
        }
	};
    for (int i =0 ;i <(int)producers.size(); i++) {
        producers[i]->print();
    };

    for (int i =0 ;i <(int)recolectors.size(); i++) {
        recolectors[i]->print();
    };

    //PRIMERO CREO LOS PRODUCERS
    for (int i =0; i<(int)producers.size(); i++) {
        producers[i]->start();
    };
    
    for (int i =0; i<(int)recolectors.size(); i++) {
        recolectors[i]->start();
    };
    
     while (_map >> m ){
        manager.save_material(m);
    }
    //std::cout << "termine de llenar las colas \n" << std::endl;
    manager.close();

    for (int i =0 ;i <(int)producers.size(); i++) {
        producers[i]->join();
    };

    for (int i =0 ;i <(int)recolectors.size(); i++) {
        recolectors[i]->join();
    };

    std::cout << "terminaron los recolectores \n" << std::endl;

    

    
    std::cout << "el inventario despues de producer\n" << std::endl;
    std::map<std::string, int>::iterator inv = inventary.resources.begin();
	for (;inv!=inventary.resources.end(); ++inv) {
        std::cout << inv->first <<": " << inv->second << std::endl;
    }
    std::cout << manager.sum << std::endl;
    std::cout << "fin" << std::endl;
    _workers.close();
    _map.close();
    return 0;
} 
    
