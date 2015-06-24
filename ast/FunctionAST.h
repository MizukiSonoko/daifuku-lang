#ifndef FUNCTION_AST
#define FUNCTION_AST

#include "PrototypeAST.h"
#include <string>
class FunctionAST{
    PrototypeAST    *Prototype;
    FunctionStmtAST *Body;

  public:
    FunctionAST(PrototypeAST *prototyp, FunctionStmt *body):
        Prototype(prototype), Body(body){}
    ~FunctionAST();

    std::string getName(){
        return Prototype->getName();
    }
    
    PrototypeAST *getPrototype(){
        return Prototype;
    }
    FunctionStmtAST *getBody(){
        return Body;
    }
};

#endif
