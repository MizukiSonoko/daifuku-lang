#ifndef TRANSLATION_UNIT_AST
#define TRANSLATION_UNIT_AST

#include <vector>
#include "Ast.hpp"
#include "FunctionAST.hpp"
#include "VariableDeclAST.hpp"

class TranslationUnitAST{
    std::vector<VariableDeclAST*> VariableDecls;
    //std::vector<FunctionAST*>  Functions;

  public:
    TranslationUnitAST(){}
    ~TranslationUnitAST(){
        for(VariableDeclAST* element : VariableDecls){
            RELEASE(element);
        }
        VariableDecls.clear();
        /*
        for(FunctionAST* element : Functions){
            RELEASE(element);
        }
        Functions.clear();
        */
    }
    
    void addVariableDecl(VariableDeclAST *variableDecl){
        VariableDecls.push_back( variableDecl );
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

    VariableDeclAST *getVariableDecl(int i){
        if(i < VariableDecls.size()){
            return VariableDecls.at(i);
        }else{
            return nullptr;
        }
    }
};

#endif
