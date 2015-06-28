#ifndef VARIABLE_DECL_AST
#define VARIABLE_DECL_AST

#include "Ast.hpp"
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

    int value;

  public:
    
    VariableDeclAST(const std::string &name,int v) : BaseAST(VariableDeclID), Name(name), value(v){}
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
    int getValue(){
        return value;
    }
    void setDeclType(DeclType type){
        Type = type;
    }
    
    DeclType getType(){
        return Type;
    }
};

#endif
