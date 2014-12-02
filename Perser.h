#ifndef PERSER_H
#define PERSER_H

#include <list>
#include <string>

#include "Token.h"

#define BUF_MAX 5

class Perser{

    std::list<Token> tokens;
    Token curTokens[BUF_MAX];
    int buf_index;
   public:
    Perser(std::list<Token>);
    void perse();
   private:
    Token LT(int);
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
