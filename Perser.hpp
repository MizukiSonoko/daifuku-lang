#ifndef PERSER_H
#define PERSER_H

#include <list>
#include <stack>
#include <vector>
#include <iostream>
#include <string>

#include "ast/TranslationUnitAST.hpp"
#include "ast/Ast.hpp"
#include "Token.hpp"

#define BUF_MAX 5

class Perser{
  private:
    std::list<Token>       tokens;
    std::stack<int>       markers;
    std::vector<Token> headTokens;
    std::string         curString;
    TranslationUnitAST       *Ast;
    int buf_index;
    
    int debug;
    void log(std::string);
  public:
    Perser(std::list<Token>,int debug);
    ~Perser(){
        RELEASE(Ast);
    }
    bool perse();
    TranslationUnitAST *getAST();
  private:


    bool TranslationUnit();

    bool VariableDecl();
    bool speculate_VariableDecl();
    bool speculate_Statement();
    bool FunctionStmt();
  
    Token LT(int);
    bool nextToken();
    bool match(Token::Type);
    void sync(int);
    void fill(int);
    int mark();
    void seek(int);
    bool isSpec();
    void release();
};

#endif
