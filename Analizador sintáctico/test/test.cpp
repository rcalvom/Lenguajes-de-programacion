#include "../libs/grammar/grammar.h"
#include <iostream>

using namespace std;

int main(){
    
    grammar g("test/rules.in");
    for(int i = 0; i < g.rules.size(); i++){
        cout << g.rules[i].value << " --> ";
        for(int j = 0; j < g.rules[i].production.size(); j++){
            cout << g.rules[i].production[j] << ' ';
        }
        cout << endl;
    }
    return 0;
}