#include "parser.h"
#include <iostream>
#include <string>
#include "file.h"

Parser::Parser(std::string& line):line(line){}

Parser::~Parser(){}

int Parser::parse_workers(File& file, std::vector<value_t>& parsed){
    std::string equal = "="; 
    while (file.read(line)) {
        size_t found = line.find(equal); 
        if (found == std::string::npos) exit(1);
        std::string type = line.substr(0, found);
        std::string _amount = line.substr(found+1);
        int amount = (int) std::stoi(_amount);
        parsed.push_back({type,amount});
    }
    return 0;
}
