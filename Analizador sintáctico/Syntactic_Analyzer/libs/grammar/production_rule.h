#include <string>
#include <vector>

class production_rule{
    public:
        std::string value;
        std::vector<std::string> production;

        production_rule(std::string value, std::vector<std::string> production);
        bool operator < (const production_rule &product_rule) const;

};