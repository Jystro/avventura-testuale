#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>
#include <vector>

class InputParser{
    public:
        InputParser (int &argc, char **argv);
        /// @author iain
	//! **MUST** receive a string, otherwise compares pointers
        const std::string& getCmdOption(const std::string &option) const;
        /// @author iain
        bool cmdOptionExists(const std::string &option) const;
    private:
        std::vector <std::string> tokens;
};




#endif // PARSER_HPP
