#ifndef LEXER_H
#define LEXER_H

#include "Token.h"

#include <list>
#include <fstream>

class Lexer{
    std::list<Token> tokens;
    std::ifstream ifs;
   public:
    Lexer(){};
    ~Lexer();
    void load(char*);
    void analyze();
    void put_result();

    std::list<Token> getTokens();
    bool isLetter(char);
};

#endif
