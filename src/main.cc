#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "lexer/lexer.hh"
#include "lexer/token.hh"

void usage()
{
    std::cout << "Usage: bfc input.bf" << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        usage();
        return 1;
    }

    std::ifstream ifile(argv[1]);

    if (!ifile.is_open())
    {
        std::cout << "bfc: '" << argv[1] << "': File not found" << std::endl;
        return 1;
    }

    std::vector<bfc::lexer::Token> tokens = bfc::lexer::lex(ifile);

    for (const bfc::lexer::Token& token : tokens)
        std::cout << token << std::endl;

    return 0;
}
