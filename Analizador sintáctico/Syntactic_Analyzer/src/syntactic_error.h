#include <stdexcept>

class syntactic_error : virtual public std::runtime_error{
    protected:
        int error_number;
        int error_offset;
    public:
        explicit syntactic_error(const std::string& msg, int err_num, int err_off) :
        std::runtime_error(msg)
        {
            error_number = err_num;
            error_offset = err_off;    
        }

        virtual ~syntactic_error() throw () { }
        
        virtual int getErrorNumber() const throw() {
            return error_number;
        }
        
        virtual int getErrorOffset() const throw() {
            return error_offset;
        }
};