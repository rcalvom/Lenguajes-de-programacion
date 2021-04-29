#include <fstream>
#include <sstream>
#include <algorithm>
#include "grammar.h"

#include <iostream>

grammar::grammar(std::string rules_path){

    // Lectura de la gramática a partir del archivo de entrada.
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

    // Calculo de simbolos NO Terminales
    for(int i = 0; i < this->rules.size(); i++){
        this->non_terminal_symbols.insert(this->rules[i].value);
    }

    // Calculo de simbolos Terminales
    for(int i = 0; i < this->rules.size(); i++){
        for(int j = 0; j < this->rules[i].production.size(); j++){
            if(this->non_terminal_symbols.end() == this->non_terminal_symbols.find(this->rules[i].production[j])){
                this->terminal_symbols.insert(this->rules[i].production[j]);
            }
        }
    }

}

// Función para identificar si un simbolo es terminal.
bool grammar::is_terminal(std::string a){
    return this->terminal_symbols.end() != this->terminal_symbols.find(a);
}

// Función para identificar si un simbolo es no terminal.
bool grammar::is_non_terminal(std::string a){
    return this->non_terminal_symbols.end() != this->non_terminal_symbols.find(a);
}

std::string grammar::to_string(){
    std::string s;
    for(int i = 0; i < this->rules.size(); i++){
        s = s + this->rules[i].value + "\t-->\t";
        for(int j = 0; j < this->rules[i].production.size(); j++){
            s = s + this->rules[i].production[j] + "\t";
        }
        s = s + "\n";
    }
    return s;
}