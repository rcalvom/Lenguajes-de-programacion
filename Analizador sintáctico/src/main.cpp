#include "../libs/syntactic_analyzer/syntactic_analyzer.h"
#include "syntactic_error.h"
#include <iostream>
#include <iostream>

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

    // Se crea el analizador léxico.
    lexical_analizer lexical("src/states.in", "src/delta.in", input, "src/reserved_words.in");

    // Se crea el analizador sintáctico.
    syntactic_analyzer syntactic(lexical, "src/grammar.in");

    // Se comienza el análisis.
    try{
        syntactic.analyze();
        cout << "El analisis sintactico ha finalizado exitosamente.";
    }catch(syntactic_error e){ // En caso de eror sintáctico, se imprime adecuadamente la excepción.
        cout << e.getMessage();
    }

    //cout << syntactic.to_string() << endl;

    return 0;
}