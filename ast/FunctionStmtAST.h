#ifndef FUNCTION_STMT_AST
#define FUNCTION_STMT_AST

#include <vector>
#include "Ast.h"
#include "VariableDeclAST.h"

class FunctionStmtAST{
    std::vector<VariableDeclAST*> VariableDecls;
    std::vector<BaseAST*>         StmtLists;

  public:
    FunctionStmtAST(){}
    ~FunctionStmtAST();
    
    void addVariableDeclaration(VariableDeclAST *variableDecl);
    void addStatement(BaseAST *stmt){
        StmtLists.push_back(stmt);
    }

    VariableDeclAST *getVariableDecl(int i){
        if(i < VariableDecls.size()){
            return VariableDecls.at(i);
        } else { 
            return NULL;
        }
    }
    
    BaseAST *getStatement(int i){
        if(i < StmtLists.size()){
            return StmtLists.at(i);
        } else { 
            return NULL;
        }
    }
};

#endif
