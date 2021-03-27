#include <vector>
#include <string>
#include "../libs/deterministic_finite_automaton.h"

class lexical_analizer : public deterministic_finite_automaton{
    public:
        std::vector<std::string> reseved_words;
        lexical_analizer(std::vector<state> states, std::string file_delta, state* initial_state, std::string str, std::string reserved_words_path);
        void execute();
    
};