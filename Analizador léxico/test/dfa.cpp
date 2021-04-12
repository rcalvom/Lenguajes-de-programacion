#include <iostream>
#include "../libs/deterministic_finite_automaton.h"

using namespace std;

int main(){

    // Autómata que acepta el lenguaje L.
    // L = {0^n 1^m | n,n >= 0}

    string str = "00111";

    deterministic_finite_automaton automaton("test/states.in", "test/delta.in", str);

    while(automaton.str.size() >= 1){
        cout << "Identifier: " << (*(automaton.current_state)).identifier << "; string: " << automaton.str << endl;   
        automaton.consume_symbol();
    }
    cout << "Identifier: " << (*(automaton.current_state)).identifier << "; string: " << automaton.str << endl;   
    cout << "Is acepted? " <<(((*(automaton.current_state)).acceptance == 1) ? "true" : "false") << endl;
    return 0;
}