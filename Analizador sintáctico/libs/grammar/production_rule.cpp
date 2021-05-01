#include "production_rule.h"

production_rule::production_rule(std::string value, std::vector<std::string> production):
value(value), production(production){ }

bool production_rule::operator < (const production_rule &product_rule) const{
    return this->value == product_rule.value ? this->production < product_rule.production : this->value < product_rule.value;
}
