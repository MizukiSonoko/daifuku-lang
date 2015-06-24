#ifndef VARIABLE_AST
#define VARIABLE_AST

#include "Ast.h"
#include <string>

class VariableAST : public BaseAST { 
  private:
    std::string Name;

  public:
    
    VariableAST(cosnt std::string &name) : BaseAST(VariableID), Name(name){}
    ~VariableAST(){}

    static inline bool classof(VariableAST const*){
        return true;
    }

    static inline bool classof(BaseAST const* base){
        return base->getID() == VariableID;
    }

    std::string getName(){ 
        return Name;
    }
};

#endif