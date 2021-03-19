#include "deterministic_finite_automaton.h"

deterministic_finite_automaton::deterministic_finite_automaton(dfa_state* initial_state, std::vector<dfa_state> states, std::string str){
    this->initial_state = initial_state;
    this->current_state = initial_state;
    this->states = states;
    this->str = str;
}

void deterministic_finite_automaton::consume_symbol(){
    char a = str.at(0);
    this->str = this->str.erase(0, 1);
    this->current_state = (*(this->current_state)).delta[a];
}

bool deterministic_finite_automaton::process_string(){
    while(this->str.size() > 0){
        this->consume_symbol();
    }
    return (*(this->current_state)).is_acceptance;
}
