#ifndef BASE_AST
#define BASE_AST

#define RELEASE(x) if(x!=NULL) delete(x); 

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
    virtual ~BaseAST();
    
    AstID getID() const {
        return ID;
    }
};
#endif
