#include <iostream>
#include "../libs/deterministic_finite_automaton.h"

using namespace std;

int main(){

    // Autómata que acepta el lenguaje L.
    // L = {0^n 1^m | n,n >= 0}

    vector<state> states(3);
    states[0] = state(0, true);
    states[1] = state(1, true);
    states[2] = state(2, false);

    string str = "0110";

    deterministic_finite_automaton automaton(states, "test/delta.in", &states[0], str);

    while(automaton.str.size() >= 1){
        cout << "Identifier: " << (*(automaton.current_state)).identifier << "; string: " << automaton.str << endl;   
        automaton.consume_symbol();
    }
    cout << "Identifier: " << (*(automaton.current_state)).identifier << "; string: " << automaton.str << endl;   
    cout << "Is acepted? " <<(((*(automaton.current_state)).acceptance == 1) ? "true" : "false") << endl;
    return 0;
}