#ifndef LEXER_H
#define LEXER_H

#include "Token.hpp"

#include <list>
#include <fstream>
#include <regex>
#include <string>

class Lexer{

    std::regex reg_special;
    std::regex reg_number;
    std::regex reg_letter;

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
    bool  isNumber(char);
    bool  isNumber(std::string);
};

#endif
