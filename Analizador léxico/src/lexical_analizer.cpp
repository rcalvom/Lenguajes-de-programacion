#include <iostream>
#include "lexical_analizer.h"

lexical_analizer::lexical_analizer(std::vector<state> states, std::string file_delta, state* initial_state, std::string str, std::string reserved_words_path)
:deterministic_finite_automaton(states, file_delta, initial_state, str)
{
    std::ifstream reserved_words_file;
    reserved_words_file.open(reserved_words_path);
    while(!reserved_words_file.eof()){
        std::string s;
        reserved_words_file >> s;
        this->reseved_words.push_back(s);
    }
    /*for(int i = 0; i< this->reseved_words.size(); i++){
        std::cout << this->reseved_words[i] << std::endl;
    }*/
    
}

void lexical_analizer::execute(){
    
}