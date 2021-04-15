#include <sstream>
#include <string>
#include "deterministic_finite_automaton.h"

// Constructor del objeto Autómata finito determinista.
deterministic_finite_automaton::deterministic_finite_automaton(std::string file_states, std::string file_delta, std::string str) :
str(str)
{   
    // Lectura de los estados.
    std::ifstream states_file;
    states_file.open(file_states.c_str());
    std::string line;
    while(getline(states_file, line)){
        std::stringstream values(line);    
        int id;
        values >> id;           
        bool isAc;
        values >> isAc;
        states.push_back(state(id, isAc));        
    }
    
    // Asignación del estado inicial y el estado actual.
    this->initial_state = &this->states[0];
    this->current_state = &this->states[0];

    // Creación del diccionario para acelerar la busqueda de las transiciones.
    this->delta.open(file_delta.c_str());
    //std::string line;
    getline(this->delta, line);
    std::stringstream values(line);
    int value;
    values >> value;
    int i = 0;
    while(values.rdbuf()->in_avail() > 0){
        values >> value;
        this->index_delta[value] = ++i;
    }
    /*for(std::map<char, int>::iterator it = this->index_delta.begin(); it != this->index_delta.end(); ++it){
        std::cout << it->first << " : " << it->second << std::endl;
    }*/
}

// Método para encontrar una transicion en el archivo delta.
int deterministic_finite_automaton::find_transition(int state, int position){
    this->delta.clear();
    this->delta.seekg(0);
    std::string s;
    getline(this->delta, s);
    for(int i = 0; i < state; i++){
        getline(this->delta, s);
    }
    int value;
    this->delta >> value;
    for(int i = 0; i < position; i++){
        this->delta >> value;
    }
    return value;
}

// Consumir un simbolo de la cadena.
void deterministic_finite_automaton::consume_symbol(){
    char a = str.at(0);
    this->str = this->str.erase(0, 1);
    this->current_state = &this->states[this->find_transition(this->current_state->identifier, this->index_delta.at(a))];
}

// Consume la cadena completa.
void deterministic_finite_automaton::consume_string(){
    while(this->str.size() > 0){
        this->consume_symbol();
    }
}

// Procesa un simbolo sin consumirlo.
void deterministic_finite_automaton::process_symbol(int position){
    char a = str.at(position);
    this->current_state = &this->states[this->find_transition(this->current_state->identifier, this->index_delta.at(a))];
}

// Procesa la cadena sin consumirla.
void deterministic_finite_automaton::process_string(){
    int position = 0;
    for(int i = 0; i < this->str.size(); i++){
        this->process_symbol(position);
    }
}