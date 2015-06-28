
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

    bool empty(){
        return Functions.empty();
    }
    FunctionAST *getFunction(int i){
        if(i < Functions.size()){
            return Functions.at(i);
        }else{
            return NULL;
        }
    }
*/
};
