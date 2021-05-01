#include <string>

class token{
    public:
        std::string type;
        std::string str;
        int state;
        int row;
        int col;

        token();
        token(std::string type, std::string str, int state, int row, int col);
};