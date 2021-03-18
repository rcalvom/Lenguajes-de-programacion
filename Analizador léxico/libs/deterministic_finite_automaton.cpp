#include "deterministic_finite_automaton.h"
#include <iostream>

using namespace std;

deterministic_finite_automaton::deterministic_finite_automaton(dfa_state* initial_state, vector<dfa_state> states, string str){
    this->initial_state = initial_state;
    this->current_state = initial_state;
    this->states = states;
    this->str = str;
}

void deterministic_finite_automaton::consume_symbol(){
    if(this->str.size() < 1){
        throw logic_error("Processing an empty string");
    }
    char a = str.at(0);

    this->str = this->str.erase(0, 1);

    //cout << "before: " << (*(this->current_state)).delta.size() << endl;

    /*if(this->current_state.delta.find(a) == this->current_state.delta.end()){
        cout << "error" << endl;
    }else{*/
        this->current_state = (*(this->current_state)).delta[a];
    //}

    //cout << "after: " << (*(this->current_state)).delta.size() << endl;
}

bool deterministic_finite_automaton::process_string(){
    while(this->str.size() > 0){
        this->consume_symbol();
    }
    return (*(this->current_state)).is_acceptance;
}
