#ifndef TRANSLATION_UNIT_AST
#define TRANSLATION_UNIT_AST

#include <vector>
#include "Ast.hpp"
#include "FunctionAST.hpp"
#include "VariableDeclAST.hpp"
#include "BinaryExprAST.hpp"

class TranslationUnitAST{
    std::vector<VariableDeclAST*> VariableDecls;
    std::vector<BinaryExprAST*>   BinaryExprs;

    template< class T> void clear(std::vector<T> vec){
        for(T element : vec){
            RELEASE(element);
        }
        vec.clear();
    } 
  public:
    TranslationUnitAST(){}
    ~TranslationUnitAST(){
        clear(VariableDecls);
        clear(BinaryExprs);
        /*
        for(VariableDeclAST* element : VariableDecls){
            RELEASE(element);
        }
        VariableDecls.clear();
        
        for(BinaryAST* element : Functions){
            RELEASE(element);
        }
        Functions.clear();
        */
    }
    
    void addVariableDecl(VariableDeclAST *variableDecl){
        VariableDecls.push_back( variableDecl );
    }
  
    void addBinaryExprAST(BinaryExprAST *binaryExpr){
        BinaryExprs.push_back( binaryExpr );
    }  
/*
    void addFunction(FunctionAST *function){
        Functions.push_back( function );
    }
*/

    bool empty(){
        return VariableDecls.empty();
    }

    int getValiableDeclsize(){
        return VariableDecls.size();
    }
    int getBinaryExprSize(){
        return BinaryExprs.size();
    }

    VariableDeclAST *getVariableDecl(int i){
        if(i < VariableDecls.size()){
            return VariableDecls.at(i);
        }else{
            return nullptr;
        }
    }
    BinaryExprAST *getBinaryExpr(int i){
        if(i < BinaryExprs.size()){
            return BinaryExprs.at(i);
        }else{
            return nullptr;
        }
    }
};

#endif
