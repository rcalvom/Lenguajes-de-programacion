#include "dfa_state.h"
#include <string>
#include <vector>

class deterministic_finite_automaton{
    public:
        dfa_state* current_state;
        std::vector<dfa_state> states;
        dfa_state* initial_state;
        std::string str;

        deterministic_finite_automaton(dfa_state* initial_state, std::vector<dfa_state> states, std::string str);
        void consume_symbol();
        bool process_string();
};