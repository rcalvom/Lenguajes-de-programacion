#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>

class syntactic_error : virtual public std::runtime_error{
    private: 
        std::string getExpected(){
            std::string s;

            /*for(std::set<std::string>::iterator it = this->expected_tokens.begin(); it != this->expected_tokens.end(); it++){
                std::cout << *it << "" << std::endl;
            }*/

            if(this->expected_tokens.find("tk_mas") != this->expected_tokens.end()){
                s = s + "\"+\", ";
            }if(this->expected_tokens.find("tk_menos") != this->expected_tokens.end()){
                s = s + "\"-\", ";
            }if(this->expected_tokens.find("tk_mult") != this->expected_tokens.end()){
                s = s + "\"*\", ";
            }if(this->expected_tokens.find("tk_div") != this->expected_tokens.end()){
                s = s + "\"/\", ";
            }if(this->expected_tokens.find("tk_mod") != this->expected_tokens.end()){
                s = s + "\"%\", ";
            }if(this->expected_tokens.find("tk_asig") != this->expected_tokens.end()){
                s = s + "\"=\", ";
            }if(this->expected_tokens.find("tk_menor") != this->expected_tokens.end()){
                s = s + "\"<\", ";
            }if(this->expected_tokens.find("tk_mayor") != this->expected_tokens.end()){
                s = s + "\">\", ";
            }if(this->expected_tokens.find("tk_menor_igual") != this->expected_tokens.end()){
                s = s + "\"<=\", ";
            }if(this->expected_tokens.find("tk_mayor_igual") != this->expected_tokens.end()){
                s = s + "\">=\", ";
            }if(this->expected_tokens.find("tk_igual") != this->expected_tokens.end()){
                s = s + "\"==\", ";
            }if(this->expected_tokens.find("tk_y") != this->expected_tokens.end()){
                s = s + "\"&&\", ";
            }if(this->expected_tokens.find("tk_o") != this->expected_tokens.end()){
                s = s + "\"||\", ";
            }if(this->expected_tokens.find("tk_dif") != this->expected_tokens.end()){
                s = s + "\"!=\", ";
            }if(this->expected_tokens.find("tk_neg") != this->expected_tokens.end()){
                s = s + "\"!\", ";
            }if(this->expected_tokens.find("tk_dosp") != this->expected_tokens.end()){
                s = s + "\":\", ";
            }if(this->expected_tokens.find("tk_pyc") != this->expected_tokens.end()){
                s = s + "\";\", ";
            }if(this->expected_tokens.find("tk_coma") != this->expected_tokens.end()){
                s = s + "\",\", ";
            }if(this->expected_tokens.find("tk_punto") != this->expected_tokens.end()){
                s = s + "\".\", ";
            }if(this->expected_tokens.find("tk_par_izq") != this->expected_tokens.end()){
                s = s + "\"(\", ";
            }if(this->expected_tokens.find("tk_par_der") != this->expected_tokens.end()){
                s = s + "\")\", ";
            }if(this->expected_tokens.find("id") != this->expected_tokens.end()){
                s = s + "\"identificador\", ";
            }if(this->expected_tokens.find("tk_entero") != this->expected_tokens.end()){
                s = s + "\"valor_entero\", ";
            }if(this->expected_tokens.find("tk_real") != this->expected_tokens.end()){
                s = s + "\"valor_real\", ";
            }if(this->expected_tokens.find("tk_caracter") != this->expected_tokens.end()){
                s = s + "\"valor_caracter\", ";
            }if(this->expected_tokens.find("tk_cadena") != this->expected_tokens.end()){
                s = s + "\"valor_cadena\", ";
            }if(this->expected_tokens.find("funcion_principal") != this->expected_tokens.end()){
                s = s + "\"funcion_principal\", ";
            }if(this->expected_tokens.find("fin_principal") != this->expected_tokens.end()){
                s = s + "\"fin_principal\", ";
            }if(this->expected_tokens.find("leer") != this->expected_tokens.end()){
                s = s + "\"leer\", ";
            }if(this->expected_tokens.find("imprimir") != this->expected_tokens.end()){
                s = s + "\"imprimir\", ";
            }if(this->expected_tokens.find("booleano") != this->expected_tokens.end()){
                s = s + "\"booleano\", ";
            }if(this->expected_tokens.find("caracter") != this->expected_tokens.end()){
                s = s + "\"caracter\", ";
            }if(this->expected_tokens.find("entero") != this->expected_tokens.end()){
                s = s + "\"entero\", ";
            }if(this->expected_tokens.find("real") != this->expected_tokens.end()){
                s = s + "\"real\", ";
            }if(this->expected_tokens.find("cadena") != this->expected_tokens.end()){
                s = s + "\"cadena\", ";
            }if(this->expected_tokens.find("si") != this->expected_tokens.end()){
                s = s + "\"si\", ";
            }if(this->expected_tokens.find("entonces") != this->expected_tokens.end()){
                s = s + "\"entonces\", ";
            }if(this->expected_tokens.find("fin_si") != this->expected_tokens.end()){
                s = s + "\"fin_si\", ";
            }if(this->expected_tokens.find("si_no") != this->expected_tokens.end()){
                s = s + "\"si_no\", ";
            }if(this->expected_tokens.find("mientras") != this->expected_tokens.end()){
                s = s + "\"mientras\", ";
            }if(this->expected_tokens.find("hacer") != this->expected_tokens.end()){
                s = s + "\"hacer\", ";
            }if(this->expected_tokens.find("fin_mientras") != this->expected_tokens.end()){
                s = s + "\"fin_mientras\", ";
            }if(this->expected_tokens.find("para") != this->expected_tokens.end()){
                s = s + "\"para\", ";
            }if(this->expected_tokens.find("fin_para") != this->expected_tokens.end()){
                s = s + "\"fin_para\", ";
            }if(this->expected_tokens.find("seleccionar") != this->expected_tokens.end()){
                s = s + "\"seleccionar\", ";
            }if(this->expected_tokens.find("entre") != this->expected_tokens.end()){
                s = s + "\"entre\", ";
            }if(this->expected_tokens.find("caso") != this->expected_tokens.end()){
                s = s + "\"caso\", ";
            }if(this->expected_tokens.find("romper") != this->expected_tokens.end()){
                s = s + "\"romper\", ";
            }if(this->expected_tokens.find("defecto") != this->expected_tokens.end()){
                s = s + "\"defecto\", ";
            }if(this->expected_tokens.find("fin_seleccionar") != this->expected_tokens.end()){
                s = s + "\"fin_seleccionar\", ";
            }if(this->expected_tokens.find("estructura") != this->expected_tokens.end()){
                s = s + "\"estructura\", ";
            }if(this->expected_tokens.find("fin_estructura") != this->expected_tokens.end()){
                s = s + "\"fin_estructura\", ";
            }if(this->expected_tokens.find("funcion") != this->expected_tokens.end()){
                s = s + "\"funcion\", ";
            }if(this->expected_tokens.find("fin_funcion") != this->expected_tokens.end()){
                s = s + "\"fin_funcion\", ";
            }if(this->expected_tokens.find("retornar") != this->expected_tokens.end()){
                s = s + "\"retornar\", ";
            }if(this->expected_tokens.find("falso") != this->expected_tokens.end()){
                s = s + "\"falso\", ";
            }if(this->expected_tokens.find("verdadero") != this->expected_tokens.end()){
                s = s + "\"verdadero\", ";
            }if(this->expected_tokens.find("EOF") != this->expected_tokens.end()){
                s = s + "\"EOF\", ";
            }
            return s.substr(0, s.size() - 2) + ".";
        }

    public:
        int row;
        int col;
        std::string found_token;
        std::set<std::string> expected_tokens;

        explicit syntactic_error(const std::string& msg, int row, int col, std::string found_token, std::set<std::string> expected_tokens) :
        std::runtime_error(msg){
            this->row = row;
            this->col = col;
            this->found_token = found_token;
            this->expected_tokens = expected_tokens;
        }

        std::string getMessage(){

            if(this->expected_tokens.find("funcion_principal") != this->expected_tokens.end() && this->expected_tokens.size() == 1){
                return "Error sintactico: falta funcion_principal";
            }

            std::stringstream s;
            s << "<";
            s << this->row;
            s << ",";
            s << this->col;
            s << "> ";
            s << "Error sintactico: se encontro: \"";
            s << this->found_token;
            s << "\"; se esperaba: ";
            s << this->getExpected();
            std::string result;
            do{
                std::string temp;
                s >> temp;
                result = result + temp + " ";
            }while(s.rdbuf()->in_avail() > 0);
            return result.substr(0, result.size() - 1);
        }

        virtual ~syntactic_error() throw () { }
        
};