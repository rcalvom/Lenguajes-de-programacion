#include "../grammar/grammar.h"
#include "../lexical_analyzer/lexical_analizer.h"


class syntactic_analyzer : public grammar{
    private:
        lexical_analizer &lexer;
        std::map<production_rule, std::set<std::string>> first;
        std::map<std::string, std::set<std::string>> follow;
        std::map<production_rule, std::set<std::string>> prediction;
        
    public:
        syntactic_analyzer(lexical_analizer &lexer, std::string rules_path);
        std::set<std::string> calculate_first(std::vector<std::string> a);
        std::set<std::string> calculate_first(std::string a);
        void calculate_follow();
        std::set<std::string> calculate_prediction(production_rule a);
        
};
