#include "../libs/syntactic_analyzer/syntactic_analyzer.h"
#include <iostream>

using namespace std;

int main(){
    // Se crea el analizador léxico.
    lexical_analizer lexical("Syntactic_Analyzer/test/states.in", "Syntactic_Analyzer/test/delta.in", "", "Syntactic_Analyzer/test/reserved_words.in");

    // Se crea el analizador sintáctico.
    syntactic_analyzer syntactic(lexical, "Syntactic_Analyzer/test/rules.in");

    cout << syntactic.to_string() << endl;
    
    return 0;
}