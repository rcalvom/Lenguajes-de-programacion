#include "state.h"

// Constructor por defecto
state::state(){ }

// Constructor con identificador y aceptación.
state::state(int identifier, bool acceptance) : 
identifier(identifier), 
acceptance(acceptance){ }