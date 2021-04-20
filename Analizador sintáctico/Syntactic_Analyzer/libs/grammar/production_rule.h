#include <string>
#include <vector>

class production_rule{
    public:
        std::string value;
        std::vector<std::string> production;

        production_rule(std::string value, std::vector<std::string> production);

};