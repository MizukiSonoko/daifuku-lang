#ifndef LEXER_H
#define LEXER_H

#include "Token.h"

#include <list>
#include <fstream>
#include <string>

class Lexer{
    std::list<Token> tokens;
    std::ifstream ifs;

    std::ifstream conf;

    int debug;
    void log(std::string);
   public:
    Lexer(int d):debug(d){};
    ~Lexer();
    void load(std::string);
    void analyze();
    void put_result();

    void load_conf();
    std::list<Token> getTokens();
    bool isLetter(char);
    int  isNumber(char);
    int  isNumber(std::string);
};

#endif
