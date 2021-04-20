#include <string>

class token{
    public:
        std::string str;
        int state;
        int row;
        int col;

        token(std::string str, int state, int row, int col);
};