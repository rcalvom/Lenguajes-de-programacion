#include <iostream>
#include "lexical_analizer.h"

lexical_analizer::lexical_analizer(std::string states_file, std::string file_delta, std::string str, std::string reserved_words_path)
:deterministic_finite_automaton(states_file, file_delta, str)
{
    std::ifstream reserved_words_file;
    reserved_words_file.open(reserved_words_path.c_str());
    while(!reserved_words_file.eof()){
        std::string s;
        reserved_words_file >> s;
        this->reserved_words.push_back(s);
    }
    /*for(int i = 0; i< this->reseved_words.size(); i++){
        std::cout << this->reseved_words[i] << std::endl;
    }*/
    this->row = 1;
    this->col = 1;
}

token lexical_analizer::next_token(){
    int pointer = 0;
    int start = 0;
    int row = this->row;
    int col = this->col;
    while(!this->current_state->acceptance){
        if(this->current_state->identifier == 19 || this->current_state->identifier == 20 || this->current_state->identifier == 24){
            if(this->str[pointer] == '*' || this->str[pointer] == '/' || this->str[pointer] == '\n'){
                this->process_symbol(pointer);
            }
        }else{
            this->process_symbol(pointer);
        }
        this->col++;
        if(this->current_state->identifier == 0 && this->str[pointer] == '\n'){
            this->row++; row++;
            this->col = 1; col = 1;
            start++;
        }else if(this->current_state->identifier == 0 && (this->str[pointer] == ' ' || this->str[pointer] == '\t')){
            col++;
            start++;
        }else if(!this->current_state->acceptance && this->str[pointer] == '\n'){
            this->row++;
            this->col = 1;
        }
        pointer++;
           
    }
    int state = this->current_state->identifier;
    this->col--;
    this->current_state = this->initial_state;
    std::string s = this->str.substr(start, pointer - start - 1);
    this->str.erase(0, pointer - 1);
    return token(s, state, row, col);
}

bool lexical_analizer::has_token(){    
    for(int i = 0; i < this->str.size(); i++){
        if(this->str[i] != ' ' && this->str[i] != '\n'){
            return true;
        }
    }
    return false;
}

bool lexical_analizer::is_reserved_word(std::string word){
    for(int i = 0; i < this->reserved_words.size(); i++){
        if(this->reserved_words[i] == word){
            return true;
        }
    }
    return false;
}