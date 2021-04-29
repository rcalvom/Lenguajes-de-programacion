#include "../libs/syntactic_analyzer/syntactic_analyzer.h"
#include "syntactic_error.h"
#include <iostream>

using namespace std;

int main(){
    // Se crea el analizador léxico.
    lexical_analizer lexical("Syntactic_Analyzer/src/states.in", "Syntactic_Analyzer/src/delta.in", "", "Syntactic_Analyzer/src/reserved_words.in");

    // Se crea el analizador sintáctico.
    syntactic_analyzer syntactic(lexical, "Syntactic_Analyzer/src/grammar.in");

    // Se comienza el análisis.
    try{
        syntactic.analyze();
    }catch(const syntactic_error &e){ // En caso de eror sintáctico, se imprime adecuadamente la excepción.
        cout << "Error!" << endl;
    }

    return 0;
}