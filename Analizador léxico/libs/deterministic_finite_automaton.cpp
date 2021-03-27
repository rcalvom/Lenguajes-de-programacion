#include <sstream>
#include <string>
#include <iostream>
#include "deterministic_finite_automaton.h"

deterministic_finite_automaton::deterministic_finite_automaton(std::vector<state> states, std::string file_delta, state* initial_state, std::string str) :
states(states), initial_state(initial_state), current_state(initial_state), str(str)
{
    this->states = states;
    this->initial_state = initial_state;
    this->current_state = current_state;
    this->delta.open(file_delta);
    std::string line;
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

void deterministic_finite_automaton::consume_symbol(){
    char a = str.at(0);
    this->str = this->str.erase(0, 1);
    this->current_state = &this->states[this->find_transition(this->current_state->identifier, this->index_delta.at(a))];
}

void deterministic_finite_automaton::consume_string(){
    while(this->str.size() > 0){
        this->consume_symbol();
    }
}