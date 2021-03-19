#include <map>

class dfa_state{

    public:
        int identifier;
        bool is_acceptance;
        std::map<char, dfa_state*> delta;

        dfa_state();
        dfa_state(bool is_acceptance);
        
};