#include <vector>
#include <string>
#include "../libs/deterministic_finite_automaton.h"

class lexical_analizer : public deterministic_finite_automaton{
    std::vector<std::string> reseved_words;
    
};