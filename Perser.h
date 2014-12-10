#ifndef PERSER_H
#define PERSER_H

#include <list>
#include <vector>
#include <string>

#include "Token.h"

#define BUF_MAX 5

class Perser{

    std::list<Token> tokens;
    std::list<int>   markers;
    std::vector<Token> headTokens;
    int buf_index;
   public:
    Perser(std::list<Token>);
    void perse();
   private:
    Token LT(int);
    void nextToken();
    void match(Token::Type);
    void sync(int);
    void fill(int);
    int mark();
    void seek(int);
    bool isSpec();
    void release();


    bool spec_label();
    void label();

    bool spec_box();
    void box();

    bool spec_daifuku();
    void daifuku();

    void kawa();
    void anko();
    void stat();
    void define();
    void add();
};

#endif
