#ifndef FUNCTION_AST
#define FUNCTION_AST

#include "PrototypeAST.hpp"
#include "FunctionStmtAST.hpp"
#include "Ast.hpp"
#include <string>
class FunctionAST{
    PrototypeAST    *Prototype;
    FunctionStmtAST *Body;

  public:
    FunctionAST(PrototypeAST *prototype, FunctionStmtAST *body):
        Prototype(prototype), Body(body){}
    ~FunctionAST(){
        RELEASE(Prototype);
        RELEASE(Body);
    }

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
