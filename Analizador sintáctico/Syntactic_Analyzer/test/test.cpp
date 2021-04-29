#include "../libs/syntactic_analyzer/syntactic_analyzer.h"
#include <iostream>

using namespace std;

int main(){
    // Se crea el analizador léxico.
    lexical_analizer lexical("Syntactic_Analyzer/src/states.in", "Syntactic_Analyzer/src/delta.in", "", "Syntactic_Analyzer/src/reserved_words.in");

    // Se crea el analizador sintáctico.
    syntactic_analyzer syntactic(lexical, "Syntactic_Analyzer/src/grammar.in");

    cout << syntactic.to_string() << endl;
    
    return 0;
}