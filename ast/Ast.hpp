#ifndef BASE_AST
#define BASE_AST

#define RELEASE(x) { delete (x); (x)=nullptr; } 

enum AstID { 
    BaseID,
    VariableDeclID,
    BinaryExprID,
    CallExprID,
    VariableID,
    NumberID,
    PrototypeID
};

class BaseAST { 
    AstID ID;

  public:

    BaseAST(AstID id):ID(id){}
    ~BaseAST(){}
    
    AstID getID() const {
        return ID;
    }
};
#endif
