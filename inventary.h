#ifndef INVENTARY_H
#define INVENTARY_H
#include <string>
#include <condition_variable>
#include <mutex>
#include <vector>
#include <map>

class Inventary{
protected:
    std::mutex mut;
    std::mutex r;
    std::condition_variable condition;
    //contador de recolectores que ingresan recursos al inventario
    int recolectors_working;
    std::map<std::string, int> resources;
    
public:
    explicit Inventary(std::vector<std::string>& materials);
    //añade un material al inventario
    void add(std::string& material);
    //se intenta obtener los elementos de recipe del inventario
    //devuelve true si se obtienen, false en caso contrario. 
    bool get_resources(std::map<std::string,int>& recipe);
    //dado una recipe se chequea si los elementos estan dentro del inventario
    bool check_completed_recipe(std::map<std::string,int>& recipe);
    //decrementa la cantidad de recolectores trabajando. 
    void update_workers();
    //devuelve true si no le van a ingresar elementos al inventario
    //false en caso contrario.
    bool is_finish();
    void set_workers(int workers);
    void print_inventary();
    ~Inventary();
};

#endif
