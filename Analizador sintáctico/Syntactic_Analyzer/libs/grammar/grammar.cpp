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

    // Generación de conjunto de Primeros.
    for(int j = 0; j < this->rules.size(); j++){
        for(int i = 0; i < this->rules.size(); i++){            // Generacion de primeros de no terminales.
            std::set<std::string> result = firsts_f(this->rules[i].production);
            this->non_terminal_firsts[this->rules[i].value].insert(result.begin(), result.end());
        }
        for(int i = 0; i < this->rules.size(); i++){            // Generacion de primero de reglas
            this->firsts[this->rules[i]] = this->firsts_f(this->rules[i].production); 
        }
    }

    /*std::cout << "PRIMEROS" << std::endl << std::endl;
    for(int i = 0; i < this->rules.size(); i++){
        std::cout << this->rules[i].value << " = { ";
        for(std::set<std::string>::iterator it = this->firsts[this->rules[i]].begin(); it!= this->firsts[this->rules[i]].end(); it++){
            std::cout << (*it) << " ";
        }
        std::cout << "}" << std::endl;
    }
    std::cout << std::endl;*/

    // Generación de conjunto de Siguientes.
    for(int k = 0; k < this->rules.size(); k++){
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
    }

    std::cout << "Siguientes" << std::endl << std::endl;
    for(std::set<std::string>::iterator it = this->non_terminal_symbols.begin(); it != this->non_terminal_symbols.end(); it++){
        std::set<std::string> next = this->nexts[*it];
        std::cout << *it << " = { ";
        for(std::set<std::string>::iterator itt = next.begin(); itt != next.end(); itt++){
            std::cout << *itt << " ";
        }
        std::cout << "}" << std::endl;
    }


    // Generación de conjunto de predicción.
    
    /*for(int i = 0; i < this->rules.size(); i++){ // Para cada regla de la gramática
        if(this->rules[i].production.size() == 0){
            for(std::set<std::string>::iterator it = this->nexts[this->rules[i].value].begin(); it != this->nexts[this->rules[i].value].end(); it++){
                this->prediction[this->rules[i]].insert(*it);
            }
        } else if(this->firsts[this->rules[i].value].end() != this->firsts[this->rules[i].value].find("")){
            for(std::set<std::string>::iterator it = this->firsts[this->rules[i].production[0]].begin(); it != this->firsts[this->rules[i].production[0]].end(); it++){
                if(*it != ""){
                    this->prediction[this->rules[i]].insert(*it);
                }
            }
            for(std::set<std::string>::iterator it = this->nexts[this->rules[i].value].begin(); it != this->nexts[this->rules[i].value].end(); it++){
                this->prediction[this->rules[i]].insert(*it);
            }
        }else{
            for(std::set<std::string>::iterator it = this->firsts[this->rules[i].production[0]].begin(); it != this->firsts[this->rules[i].production[0]].end(); it++){
                this->prediction[this->rules[i]].insert(*it);
            }
        }
        
    }*/

    /*std::cout << "PREDICCIÓN" << std::endl << std::endl;
    for(int i = 0; i < this->rules.size(); i++){
        std::cout << this->rules[i].value << " --> ";
        for(int j = 0; j < this->rules[i].production.size(); j++){
            std::cout << this->rules[i].production[j] << " ";
        }
        std::cout << " = \n{ ";
        for(std::set<std::string>::iterator it = this->prediction[this->rules[i]].begin(); it != this->prediction[this->rules[i]].end(); it++){
            std::cout << *it << " ";
        }
        std::cout << "}" << std::endl;
    }*/
    
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

std::set<std::string> grammar::firsts_f(std::vector<std::string> a){
    std::set<std::string> firsts;
    if(a.size() == 0){          
        firsts.insert("");  
    }else{
        if(this->is_terminal(a[0])){
            firsts.insert(a[0]);
        }else{
            std::set<std::string> f = firsts_f(a[0]);
            firsts.insert(f.begin(), f.end());
            firsts.erase("");
            if(f.find("") != f.end()){
                if(a.size() == 1){ 
                    firsts.insert(""); 
                }
                if(a.size() > 1){
                    std::vector<std::string> new_a = a;
                    new_a.erase(new_a.begin());
                    std::set<std::string> sub_a = firsts_f(new_a);
                    firsts.insert(sub_a.begin(), sub_a.end()); 
                }
            }
        }
    }
    return firsts;
}

std::set<std::string> grammar::firsts_f(std::string a){
    if(this->is_non_terminal(a)){        
        return this->non_terminal_firsts[a];
    }else{
        std::cout << a << ": ";
        std::vector<std::string> vector;
        vector.push_back(a);
        return firsts_f(a);
    }
    
}

std::set<std::string> grammar::follow(std::string a){
    std::set<std::string> f;
    return f;
}

std::set<std::string> grammar::prediction_f(production_rule a){
    std::set<std::string> f;
    return f;
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