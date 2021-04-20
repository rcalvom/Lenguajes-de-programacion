#include <vector>
#include <set>
#include <map>
#include <string>
#include "production_rule.h"

class grammar{
    private:
        std::set<std::string> non_terminal_symbols;
        std::set<std::string> terminal_symbols;
    public:
        std::vector<production_rule> rules;
        std::map<std::string, std::set<std::string>> firsts;
        std::map<std::string, std::set<std::string>> nexts;
        std::map<production_rule, std::set<std::string>> prediction;

        grammar(std::string rules_path);
        std::string to_string();
};