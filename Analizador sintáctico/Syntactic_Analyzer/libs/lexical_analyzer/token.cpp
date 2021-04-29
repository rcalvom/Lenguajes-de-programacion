#include "token.h"

token::token(){}

token::token(std::string str, int state, int row, int col){
    this->str = str;
    this->state = state;
    this->row = row;
    this->col = col;
}