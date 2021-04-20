#include <fstream>
#include <sstream>
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

    // Generación de conjunto de Primeros.

    for(int i = this->rules.size() - 1; i >= 0; i--){  // Para cada regla.
        if(this->rules[i].production.size() == 0){ // Si la producción es epsilon.
            this->firsts[this->rules[i].value].insert(""); // Se inserta epsilon únicamente.
        }else{                                      // Si la producción no es vacia
            int j = 0;
            do{
                if(this->terminal_symbols.end() != this->terminal_symbols.find(this->rules[i].production[j])){ // Si el simbolo es terminal.
                    this->firsts[this->rules[i].value].insert(this->rules[i].production[j]); // Se inserta unicamente ese terminal.
                    break;
                }else{ // Si el simbolo es no terminal.                    
                    for(std::set<std::string>::iterator it = this->firsts[this->rules[i].production[j]].begin(); it != this->firsts[this->rules[i].production[j]].end(); it++){
                        if(*it != ""){
                            this->firsts[this->rules[i].value].insert(*it); // Se añade los primeros del primer simbolo de la producción.
                        }
                    }
                    if(this->firsts[this->rules[i].production[j]].find("") != this->firsts[this->rules[i].production[j]].end()){ // Si epsilon pertenese a los primeros del primer simbolo de la producción
                        if(this->rules[i].production.size() - j > 1){
                        }else{
                            this->firsts[this->rules[i].value].insert("");
                            break;
                        }
                    }else{
                        break;
                    }
                }
                
            }while(++j < this->rules[i].production.size());
        }
    }

    for(std::set<std::string>::iterator it = this->terminal_symbols.begin(); it != this->terminal_symbols.end(); it++){
        this->firsts[*it].insert(*it);
    }


    /*for(std::set<std::string>::iterator it = this->non_terminal_symbols.begin(); it != this->non_terminal_symbols.end(); it++){
        std::set<std::string> first = this->firsts[*it];
        std::cout << *it << " = { ";
        for(std::set<std::string>::iterator itt = first.begin(); itt != first.end(); itt++){
            std::cout << *itt << " ";
        }
        std::cout << "}" << std::endl;
    }

    for(std::set<std::string>::iterator it = this->terminal_symbols.begin(); it != this->terminal_symbols.end(); it++){
        std::set<std::string> first = this->firsts[*it];
        std::cout << *it << " = { ";
        for(std::set<std::string>::iterator itt = first.begin(); itt != first.end(); itt++){
            std::cout << *itt << " ";
        }
        std::cout << "}" << std::endl;
    }*/

    // Generación de conjunto de Siguientes.

    for(int i = 0; i < this->rules.size(); i++){  // Para cada regla.
        if(i == 0){ // Si es el simbolo inicial de la gramática se inserta EOF
            this->nexts[this->rules[i].value].insert("$");
        }
        for(int j = 0; j < this->rules[i].production.size(); j++){          // Para cada simbolo en la producción de una regla
            if(this->non_terminal_symbols.end() != this->non_terminal_symbols.find(this->rules[i].production[j])){ // Si el simbolo es no terminal.
                if(j == this->rules[i].production.size() - 1){
                    for(std::set<std::string>::iterator it = this->nexts[this->rules[i].value].begin(); it != this->nexts[this->rules[i].value].end(); it++){
                        this->nexts[this->rules[i].production[j]].insert(*it); // Se añade los primeros del siguiente simbolo.
                    }
                }else {
                    for(std::set<std::string>::iterator it = this->firsts[this->rules[i].production[j + 1]].begin(); it != this->firsts[this->rules[i].production[j + 1]].end(); it++){
                        if(*it != ""){
                            this->nexts[this->rules[i].production[j]].insert(*it); // Se añade los primeros del siguiente simbolo.
                        }
                    }
                    if(this->firsts[this->rules[i].production[j + 1]].end() != this->firsts[this->rules[i].production[j + 1]].find("")){
                        for(std::set<std::string>::iterator it = this->nexts[this->rules[i].value].begin(); it != this->nexts[this->rules[i].value].end(); it++){
                            this->nexts[this->rules[i].production[j]].insert(*it); // Se añade los primeros del siguiente simbolo.
                        }
                    }
                }
            }
        }
    }

    for(int i = this->rules.size() - 1; i >= 0; i--){  // Para cada regla.
        if(i == 0){ // Si es el simbolo inicial de la gramática se inserta EOF
            this->nexts[this->rules[i].value].insert("$");
        }
        for(int j = 0; j < this->rules[i].production.size(); j++){          // Para cada simbolo en la producción de una regla
            if(this->non_terminal_symbols.end() != this->non_terminal_symbols.find(this->rules[i].production[j])){ // Si el simbolo es no terminal.
                if(j == this->rules[i].production.size() - 1){
                    for(std::set<std::string>::iterator it = this->nexts[this->rules[i].value].begin(); it != this->nexts[this->rules[i].value].end(); it++){
                        this->nexts[this->rules[i].production[j]].insert(*it); // Se añade los primeros del siguiente simbolo.
                    }
                }else {
                    for(std::set<std::string>::iterator it = this->firsts[this->rules[i].production[j + 1]].begin(); it != this->firsts[this->rules[i].production[j + 1]].end(); it++){
                        if(*it != ""){
                            this->nexts[this->rules[i].production[j]].insert(*it); // Se añade los primeros del siguiente simbolo.
                        }
                    }
                    if(this->firsts[this->rules[i].production[j + 1]].end() != this->firsts[this->rules[i].production[j + 1]].find("")){
                        for(std::set<std::string>::iterator it = this->nexts[this->rules[i].value].begin(); it != this->nexts[this->rules[i].value].end(); it++){
                            this->nexts[this->rules[i].production[j]].insert(*it); // Se añade los primeros del siguiente simbolo.
                        }
                    }
                }
            }
        }
    }

    for(std::set<std::string>::iterator it = this->non_terminal_symbols.begin(); it != this->non_terminal_symbols.end(); it++){
        std::set<std::string> next = this->nexts[*it];
        std::cout << *it << " = { ";
        for(std::set<std::string>::iterator itt = next.begin(); itt != next.end(); itt++){
            std::cout << *itt << " ";
        }
        std::cout << "}" << std::endl;
    }


    // Generación de conjunto de predicción.
    
    /*std::cout << "{ ";
    for(std::set<std::string>::iterator it = this->terminal_symbols.begin(); it != this->terminal_symbols.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "}" << std::endl;
    std::cout << "{ ";
    for(std::set<std::string>::iterator it = this->non_terminal_symbols.begin(); it != this->non_terminal_symbols.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << "}" << std::endl;*/
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