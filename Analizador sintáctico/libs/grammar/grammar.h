#include <vector>
#include <set>
#include <string>
#include "production_rule.h"

class grammar{
    public:
        std::set<std::string> non_terminal_symbols;
        std::set<std::string> terminal_symbols;
        std::vector<production_rule> rules;
        grammar(std::string rules_path);
};