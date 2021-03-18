#include "dfa_state.h"

dfa_state::dfa_state(){ }

dfa_state::dfa_state(bool is_acceptance){
    this->is_acceptance = is_acceptance;
}
