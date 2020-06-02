#ifndef PARSER_H
#define PARSER_H
#include "value.h"
#include <vector>
#include <string>
class File;

class Parser{
private:
    std::string& line;
public:
    explicit Parser(std::string& line);
    ~Parser();
    int parse_workers(File& file, std::vector<value_t>& parsed);
};


#endif
