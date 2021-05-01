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
    /*for(int i = 0; i< this->reserved_words.size(); i++){
        std::cout << this->reserved_words[i] << std::endl;
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
    std::string type;
    switch(state){
        case 2: // Identificador o palabra reservada
            if(this->is_reserved_word(s)){
                type = s;    
            }else{
                type = "id";
            }
            break;
        //case 5: // Entero y Token .
        //    cout << "<tk_entero," << t.row << "," << t.col << ">" << endl;
        //   cout << "<tk_punto," << t.row << "," << t.col + t.str.size() -1  << ">" << endl; 
        //    break;
        case 7: // Número Real
            type = "tk_real";
            break;
        case 8: // Número Entero
            type = "tk_entero";
            break;
        case 13: // Caracter
            type = "tk_caracter";
            break;
        case 17: // Cadena
            type = "tk_cadena";
            break;
        case 22: // Bloque de comentarios
            type = "comment";
            break;
        case 23: // Token /
            type = "tk_div";
            break;
        case 26: // Comentario de linea
            type = "comment";
            break;
        case 28: // Token +
            type = "tk_mas";
            break;
        case 30: // Token -
            type = "tk_menos";
            break;
        case 32: // Token *
            type = "tk_mult";
            break;
        case 34: // Token %
            type = "tk_mod";
            break;
        case 36: // Token =
            type = "tk_asig";
            break;
        case 38: // Token ==
            type = "tk_igual";
            break;
        case 40: // Token <
            type = "tk_menor";
            break;
        case 42: // Token <=
            type = "tk_menor_igual";
            break;
        case 44: // Token >
            type = "tk_mayor";
            break;
        case 46: // Token >=
            type = "tk_mayor_igual";
            break;
        case 49: // Token &&
            type = "tk_y";
            break;
        case 52: // Token ||
            type = "tk_o";
            break;
        case 54: // Token !
            type = "tk_neg";
            break;
        case 56: // Token !=
            type = "tk_dif";
            break;
        case 58: // Token :
            type = "tk_dosp";
            break;
        case 60: // Token ;
            type = "tk_pyc";
            break;
        case 62: // Token .
            type = "tk_punto";
            break;
        case 64: // Token ,
            type = "tk_coma";
            break;
        case 66: // Token (
            type = "tk_par_izq";
            break;
        case 68: // Token )
            type = "tk_par_der";
            break;
    }
    return token(type, s, state, row, col);
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