
enum AstID { 
    BaseID,
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

