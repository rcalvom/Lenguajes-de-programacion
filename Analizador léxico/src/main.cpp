#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "lexical_analizer.h"

using namespace std;

int main(){

    string input;
    string line;
    while(getline(cin, line)){
        input = input + line + '\n';
    }

    input = input + '\n';

    for(int i = 0; i < input.size(); i++){
        if(input[i] == '\r'){
            input.erase(i, 1);
            i--;
        }
    }

    lexical_analizer analizer("src/states.in", "src/delta.in", input, "src/reserved_words.in");
    
    while(analizer.has_token()){
        try{
            token t = analizer.next_token();
            switch(t.state){
                case 2: // Identificador o palabra reservada
                    if(analizer.is_reserved_word(t.str)){
                        cout << "<" << t.str << "," << t.row << "," << t.col << ">" << endl;    
                    }else{
                        cout << "<id," << t.str << "," << t.row << "," << t.col << ">" << endl;
                    }
                    break;
                case 5: // Entero y Token .
                    cout << "<tk_entero," << t.row << "," << t.col << ">" << endl;
                    cout << "<tk_punto," << t.row << "," << t.col + t.str.size() -1  << ">" << endl; 
                    break;
                case 7: // Número Real
                    cout << "<tk_real," << t.str << "," << t.row << "," << t.col << ">" << endl;
                    break;
                case 8: // Número Entero
                    cout << "<tk_entero," << t.str << "," << t.row << "," << t.col << ">" << endl;
                    break;
                case 13: // Caracter
                    cout << "<tk_caracter," << t.str << "," << t.row << "," << t.col << ">" << endl;
                    break;
                case 17: // Cadena
                    cout << "<tk_cadena," << t.str << "," << t.row << "," << t.col << ">" << endl;
                    break;
                case 22: // Bloque de comentarios
                    break;
                case 23: // Token /
                    cout << "<tk_div," << t.row << "," << t.col << ">" << endl;
                    break;
                case 26: // Comentario de linea
                    break;
                case 28: // Token +
                    cout << "<tk_mas," << t.row << "," << t.col << ">" << endl;
                    break;
                case 30: // Token -
                    cout << "<tk_menos," << t.row << "," << t.col << ">" << endl;
                    break;
                case 32: // Token *
                    cout << "<tk_mult," << t.row << "," << t.col << ">" << endl;
                    break;
                case 34: // Token %
                    cout << "<tk_mod," << t.row << "," << t.col << ">" << endl;
                    break;
                case 36: // Token =
                    cout << "<tk_asig," << t.row << "," << t.col << ">" << endl;
                    break;
                case 38: // Token ==
                    cout << "<tk_igual," << t.row << "," << t.col << ">" << endl;
                    break;
                case 40: // Token <
                    cout << "<tk_menor," << t.row << "," << t.col << ">" << endl;
                    break;
                case 42: // Token <=
                    cout << "<tk_menor_igual," << t.row << "," << t.col << ">" << endl;
                    break;
                case 44: // Token >
                    cout << "<tk_mayor," << t.row << "," << t.col << ">" << endl;
                    break;
                case 46: // Token >=
                    cout << "<tk_mayor_igual," << t.row << "," << t.col << ">" << endl;
                    break;
                case 49: // Token &&
                    cout << "<tk_y," << t.row << "," << t.col << ">" << endl;
                    break;
                case 52: // Token ||
                    cout << "<tk_o," << t.row << "," << t.col << ">" << endl;
                    break;
                case 54: // Token !
                    cout << "<tk_neg," << t.row << "," << t.col << ">" << endl;
                    break;
                case 56: // Token !=
                    cout << "<tk_dif," << t.row << "," << t.col << ">" << endl;
                    break;
                case 58: // Token :
                    cout << "<tk_dosp," << t.row << "," << t.col << ">" << endl;
                    break;
                case 60: // Token ;
                    cout << "<tk_pyc," << t.row << "," << t.col << ">" << endl;
                    break;
                case 62: // Token .
                    cout << "<tk_punto," << t.row << "," << t.col << ">" << endl;
                    break;
                case 64: // Token ,
                    cout << "<tk_coma," << t.row << "," << t.col << ">" << endl;
                    break;
                case 66: // Token (
                    cout << "<tk_par_izq," << t.row << "," << t.col << ">" << endl;
                    break;
                case 68: // Token )
                    cout << "<tk_par_der," << t.row << "," << t.col << ">" << endl;
                    break;            
            }
        }catch(exception e){
            cout << ">>> Error lexico (linea: " << analizer.row <<", posicion: " << analizer.col <<")" << endl;
            return 0;
        }
    }

    return 0;
}