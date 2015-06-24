#ifndef VARIABLE_DECL_AST
#define VARIABLE_DECL_AST

#include "Ast.h"
#include <string>

class VariableDeclAST : public BaseAST { 
  public:
    typedef enum{
        param,
        local
    } DeclType;
  private:
    std::string Name;
    DeclType Type;

  public:
    
    VariableDeclAST(const std::string &name) : BaseAST(VariableDeclID), Name(name){}
    ~VariableDeclAST(){}

    static inline bool classof(VariableDeclAST const*){
        return true;
    }

    static inline bool classof(BaseAST const* base){
        return base->getID() == VariableDeclID;
    }

    std::string getName(){ 
        return Name;
    }
    void setDeclType(DeclType type){
        Type = type;
    }
    
    DeclType getType(){
        return Type;
    }
};

#endif
