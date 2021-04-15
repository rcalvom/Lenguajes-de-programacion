#include "../grammar/grammar.h"
#include "../lexical_analyzer/lexical_analizer.h"


class syntactic_analyzer : grammar{
    private:
        lexical_analizer lexical_analizer;
    public:
        syntactic_analyzer(std::string states_file, std::string file_delta, std::string str, std::string reserved_words_path);
};