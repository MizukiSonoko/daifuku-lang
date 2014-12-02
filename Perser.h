#ifndef PERSER_H
#define PERSER_H

#include <list>
#include <string>

#include "Token.h"

class Perser{
    std::list<Token> tokens;
    Token curToken;
   public:
    Perser(std::list<Token>);
    void perse();
   private:
    void nextToken();
    void match(std::string type);

    void daifuku();
    void kawa();
    void anko();
    void stat();
    void define();
    void add();
};

#endif
