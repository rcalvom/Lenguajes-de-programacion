#include <vector>
#include <set>
#include <map>
#include <string>
#include "production_rule.h"

class grammar{
    protected:
        std::vector<production_rule> rules;
        std::set<std::string> non_terminal_symbols;
        std::set<std::string> terminal_symbols;
        std::string initial_symbol;

    public:
        grammar(std::string rules_path);
        bool is_terminal(std::string a);
        bool is_non_terminal(std::string a);
        std::string to_string();
};