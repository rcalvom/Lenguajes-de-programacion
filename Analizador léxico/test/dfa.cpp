#include <iostream>
#include "../libs/deterministic_finite_automaton.h"

using namespace std;

int main(){

    // Autómata que acepta el lenguaje L.
    // L = {0^n 1^m | n,n >= 0}

    vector<dfa_state> states(3);
    states[0] = dfa_state(true);
    states[1] = dfa_state(true);
    states[2] = dfa_state(false);

    states[0].value = 0;
    states[1].value = 1;
    states[2].value = 2;

    states[0].delta['0'] = &states[0];
    states[0].delta['1'] = &states[1];

    states[1].delta['0'] = &states[2];
    states[1].delta['1'] = &states[1];

    states[2].delta['0'] = &states[2];
    states[2].delta['1'] = &states[2];

    string str = "00001111101";

    deterministic_finite_automaton automaton(&states[0], states, str);

    while(automaton.str.size() >= 1){
        cout << "Value: " << (*(automaton.current_state)).value << "; string: " << automaton.str << endl;
        automaton.consume_symbol();
        
    }

    cout << (((*(automaton.current_state)).is_acceptance == 1) ? "true" : "false") << endl;
    return 0;
}