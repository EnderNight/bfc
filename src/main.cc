#include <fstream>
#include <iostream>
#include <string>
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

    std::string line;
    std::string file;

    while (std::getline(ifile, line))
    {
        file.append(line);
    }

    // std::cout << file << std::endl;
    
    bfc::lexer::Token token(bfc::lexer::TokenType::TOKEN_DOT, 3);

    std::cout << token << std::endl;


    return 0;
}
