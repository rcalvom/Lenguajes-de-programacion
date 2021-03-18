#include "dfa_state.h"
#include <string>
#include <vector>

using namespace std;

class deterministic_finite_automaton{
    public:
        dfa_state* current_state;
        vector<dfa_state> states;
        dfa_state* initial_state;
        string str;

        deterministic_finite_automaton(dfa_state* initial_state, vector<dfa_state> states, string str);
        void consume_symbol();
        bool process_string();
};