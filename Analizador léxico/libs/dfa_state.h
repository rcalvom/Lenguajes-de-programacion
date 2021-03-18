#include <map>

using namespace std;

class dfa_state{

    public:
        int value;
        bool is_acceptance;
        map<char, dfa_state*> delta;

        dfa_state();
        dfa_state(bool is_acceptance);
        
};