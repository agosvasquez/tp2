#ifndef FILE_H
#define FILE_H
#include <exception>
#include <fstream>
#include <string>

struct BadFile : public std::exception {
public:
   const char *what() const throw() {
      return "File couldn't be opened!\n";
   }
};

class File {
    private:
        std::ifstream file;
    public:
    explicit File(std::string);   
    ~File();
    //lee una linea de un file. 
    //devuelve true cuando la lectura fue exitosa, false en caso contrario
    bool read(std::string& line);
    //lee un caracter de un file. 
    //devuelve true cuando la lectura fue exitosa, false en caso contrario
    bool read(char& c);
};


#endif
