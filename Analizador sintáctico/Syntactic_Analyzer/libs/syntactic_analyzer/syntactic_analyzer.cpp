#include <iostream>
#include "syntactic_analyzer.h"
#include "syntactic_error.h"

syntactic_analyzer::syntactic_analyzer(lexical_analizer &lex, std::string rules_path) :
grammar(rules_path), lexer(lex)
{
    // Generación de conjunto de Primeros.
    for(int j = 0; j < this->rules.size(); j++){
        for(int i = 0; i < this->rules.size(); i++){
            this->first[this->rules[i]] = this->calculate_first(this->rules[i].production); 
        }
    }

    // Generación de conjunto de Siguientes.
    for(std::set<std::string>::iterator it = this->non_terminal_symbols.begin(); it != this->non_terminal_symbols.end(); it++){
        this->follow[*it] = std::set<std::string>();
    }
    for(int i = 0; i < this->rules.size(); i++){
         this->calculate_follow();
    }

    // Generación del conjunto de Predicción.
    for(int i = 0; i < this->rules.size(); i++){ 
        this->prediction[this->rules[i]] = this->calculate_prediction(this->rules[i]);
    }

}

void syntactic_analyzer::analyze(){
    this->t = this->lexer.next_token();
    this->evaluate(this->initial_symbol);
    /*if(this->t.str != "$"){
        throw(syntactic_error("a", 0, 0));
    }*/
}

void syntactic_analyzer::evaluate(std::string a){
    std::vector<production_rule> rules;
    for(int i = 0; i < this->rules.size(); i++){
        if(this->rules[i].value == a){
            rules.push_back(this->rules[i]);
        }
    }
    for(int i = 0; i < rules.size(); i++){
        for(std::set<std::string>::iterator it = this->prediction[rules[i]].begin(); it != this->prediction[rules[i]].end(); it++){
            if(this->t.str == *it){
                for(int j = 0; j < rules[i].production.size(); j++){
                    if(this->is_non_terminal(rules[i].production[j])){
                        this->evaluate(rules[i].production[j]);
                    }else{
                        this->match(rules[i].production[j]);
                    }
                }
                return;
            }
        }
    }
    //throw(syntactic_error("a", 0 , 0));
}

void syntactic_analyzer::match(std::string t){
    if(t == ""){
        return;
    }
    /*if(this->t.str == t){
        this->t = this->lexer.next_token();
    }else{*/
    //    throw(syntactic_error("a", 0 ,0));
    //}
}

std::set<std::string> syntactic_analyzer::calculate_first(std::vector<std::string> a){
    std::set<std::string> firsts;
    if(a.size() == 0){          
        firsts.insert("");  
    }else{
        if(this->is_terminal(a[0])){
            firsts.insert(a[0]);
        }else{
            std::set<std::string> f = this->calculate_first(a[0]);
            firsts.insert(f.begin(), f.end());
            firsts.erase("");
            if(f.find("") != f.end()){
                if(a.size() == 1){ 
                    firsts.insert(""); 
                }
                if(a.size() > 1){
                    std::vector<std::string> new_a = a;
                    new_a.erase(new_a.begin());
                    std::set<std::string> sub_a = this->calculate_first(new_a);
                    firsts.insert(sub_a.begin(), sub_a.end()); 
                }
            }
        }
    }
    return firsts;
}

std::set<std::string> syntactic_analyzer::calculate_first(std::string a){
    std::set<std::string> result;
    if(this->is_non_terminal(a)){
        for(int i = 0; i < this->rules.size(); i++){
            if(this->rules[i].value == a){
                result.insert(this->first[this->rules[i]].begin(), this->first[this->rules[i]].end());
            }
        }      
    }else{
        result.insert(a);
    }
    return result;
}

void syntactic_analyzer::calculate_follow(){
    for(int i = 0; i < this->rules.size(); i++){  
        if(i == 0){
            this->follow[this->rules[i].value].insert("$");
        }
        for(int j = 0; j < this->rules[i].production.size(); j++){
            if(this->is_non_terminal(this->rules[i].production[j])){
                if(j == this->rules[i].production.size() - 1){
                    std::set<std::string> result = this->follow[this->rules[i].value];
                    this->follow[this->rules[i].production[j]].insert(result.begin(), result.end());
                }else{
                    std::vector<std::string> betha;
                    for(int k = 1; k < this->rules[i].production.size() - j; k++){
                        betha.push_back(this->rules[i].production[j + k]);
                    }
                    std::set<std::string> result = this->calculate_first(betha);
                    this->follow[this->rules[i].production[j]].insert(result.begin(), result.end());
                    if(result.find("") != result.end()){
                        this->follow[this->rules[i].production[j]].erase("");
                        std::set<std::string> result_nexts = this->follow[this->rules[i].value];
                        this->follow[this->rules[i].production[j]].insert(result_nexts.begin(), result_nexts.end());
                    }
                }
            }
        }
    }
}

std::set<std::string> syntactic_analyzer::calculate_prediction(production_rule a){
    std::set<std::string> result;
    if(this->first[a].find("") != this->first[a].end()){
        result = this->first[a];
        result.erase("");
        result.insert(this->follow[a.value].begin(), this->follow[a.value].end());
    }else{
        result = this->first[a];
    }
    return result;
}

std::string syntactic_analyzer::to_string(){
    std::string s = grammar::to_string();
    s = s + "\nPRIMEROS\n\n";
    for(int i = 0; i < this->rules.size(); i++){
        s = s + this->rules[i].value + " = { ";
        for(std::set<std::string>::iterator it = this->first[this->rules[i]].begin(); it!= this->first[this->rules[i]].end(); it++){
            s = s + (*it) + " ";
        }
        s = s + "}\n";
    }
    s = s + "\n";

    s = s + "\nSIGUIENTES\n\n";
    for(std::set<std::string>::iterator it = this->non_terminal_symbols.begin(); it != this->non_terminal_symbols.end(); it++){
        std::set<std::string> next = this->follow[*it];
        s = s + *it + " = { ";
        for(std::set<std::string>::iterator itt = next.begin(); itt != next.end(); itt++){
            s = s + *itt + " ";
        }
        s = s + "}\n";
    }
    s = s + "\n";   

    s = s + "\nPREDICCIÓN\n\n";
    for(int i = 0; i < this->rules.size(); i++){
        s = s + this->rules[i].value + " -> ";
        for(int j = 0; j < this->rules[i].production.size(); j++){
            s = s + this->rules[i].production[j] + " ";
        }
        s = s + " = \n{ ";
        for(std::set<std::string>::iterator it = this->prediction[this->rules[i]].begin(); it != this->prediction[this->rules[i]].end(); it++){
            s = s + *it + " ";
        }
        s = s + "}\n";
    }
    return s;
}