#include <vector>
#include <queue>
#include <string>
#include "../libs/deterministic_finite_automaton.h"
#include "token.h"

class lexical_analizer : public deterministic_finite_automaton{       
    public:
        int row;
        int col;
        std::vector<std::string> reserved_words;

        lexical_analizer(std::string states_file, std::string file_delta, std::string str, std::string reserved_words_path);
        token next_token();
        bool has_token();
        bool is_reserved_word(std::string word);
    
};