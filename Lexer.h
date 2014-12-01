#ifndef LEXER_H
#define LEXER_H

#include "Token.h"

#include <vector>
#include <fstream>

class Lexer{
    std::vector<Token> tokens;
    std::ifstream ifs;
   public:
    Lexer(char*);
    ~Lexer();
    void analyze();
    void put_result();

    bool isLetter(char);
};

#endif
