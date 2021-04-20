#include <string>
#include <vector>
#include <map>
#include <fstream>
#include "state.h"

class deterministic_finite_automaton{
    private:
        int find_transition(int state, int position);
    public:
        std::vector<state> states;
        std::ifstream delta;
        state* initial_state;
        state* current_state;
        std::string str;
        std::map<char, int> index_delta;

        deterministic_finite_automaton(std::string file_states, std::string file_delta, std::string str);
        void consume_symbol();
        void consume_string();
        void process_symbol(int position);
        void process_string();
};