
#define RELEASE(x) if(x!=NULL) delete(x); 

enum AstID { 
    BaseID,
    VariavleDeclID,
    BinaryExprID,
    CallExprID,
    VariableID,
    NumberID
};

class BaseAST { 
    AstID id;

  public:

    BaseAST(AstID id):ID(id){}
    virtual ~BaseAST();
    
    AstID getID() const {
        return ID;
    }
};

