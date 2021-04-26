#include <vector>
#include <set>
#include <map>
#include <string>
#include "production_rule.h"

class grammar{
    private:
        std::set<std::string> non_terminal_symbols;
        std::set<std::string> terminal_symbols;

        std::set<std::string> firsts_f(std::vector<std::string> a);
        std::set<std::string> firsts_f(std::string a);
        std::set<std::string> follow(std::string a);
        std::set<std::string> prediction_f(production_rule a);
    public:
        std::vector<production_rule> rules;
        std::map<production_rule, std::set<std::string>> firsts;
        std::map<std::string, std::set<std::string>> non_terminal_firsts;
        std::map<std::string, std::set<std::string>> nexts;
        std::map<production_rule, std::set<std::string>> prediction;

        grammar(std::string rules_path);
        bool is_terminal(std::string a);
        bool is_non_terminal(std::string a);
        std::string to_string();
};