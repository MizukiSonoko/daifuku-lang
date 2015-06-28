#ifndef BINARY_EXPR_AST
#define BINARY_EXPR_AST

#include "Ast.hpp"
#include <string>

class BinaryExprAST : public BaseAST { 
  private:
    std::string Op;
    BaseAST *LHS, *RHS;

  public:
    
    BinaryExprAST(std::string &op, BaseAST *lhs, BaseAST *rhs) : 
        BaseAST(BinaryExprID), Op(op), LHS(lhs), RHS(rhs){}
    ~BinaryExprAST(){
        RELEASE(LHS);
        RELEASE(RHS);
    }

    static inline bool classof(BinaryExprAST const*){
        return true;
    }

    static inline bool classof(BaseAST const* base){
        return base->getID() == BinaryExprID;
    }

    std::string getOp(){ 
        return Op;
    }
    
    BaseAST *getLHS(){
        return LHS;
    }

    BaseAST *getRHS(){
        return RHS;
    }
};

#endif
