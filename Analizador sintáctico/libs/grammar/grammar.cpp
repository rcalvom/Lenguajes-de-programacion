#include <fstream>
#include <sstream>
#include "grammar.h"

#include <iostream>
using namespace std;

grammar::grammar(std::string rules_path){
    std::ifstream rules_file;
    rules_file.open(rules_path.c_str());
    std::string line;
    while(getline(rules_file, line)){
        std::stringstream values(line);    
        std::string left;
        values >> left;           
        std::vector<std::string> production;
        while(values.rdbuf()->in_avail() > 0){
            std::string production_symbol;
            values >> production_symbol;
            production.push_back(production_symbol);
        }
        this->rules.push_back(production_rule(left, production));         
    }
}