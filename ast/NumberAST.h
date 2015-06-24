
#include "Ast.h"
#include <string>

class NumberAST : public BaseAST { 
  private:
    int Val;

  public:
    
    NumberAST(int val) : BaseAST(NumberID), Val(val){}
    ~NumberAST(){}

    static inline bool classof(NumberAST const*){
        return true;
    }

    static inline bool classof(BaseAST const* base){
        return base->getID() == NumberID;
    }

    int getVal(){ 
        return Val;
    }
};

