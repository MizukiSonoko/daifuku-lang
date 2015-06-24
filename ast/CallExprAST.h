
#include "Ast.h"
#include <string>
#include <vector>

class CallExprAST : public BaseAST { 
  private:
    std::string Callee;
    std::vector<BaseAST*> Args;

  public:
    
    CallExprAST(const std::string &callee, std::vector<BaseAST*> &args) : 
        BaseAST(CallExprID), Callee(callee), Args(args){}
    ~CallExprAST(){
    
    }

    static inline bool classof(CallExprAST const*){
        return true;
    }

    static inline bool classof(BaseAST const* base){
        return base->getID() == CallExprID;
    }

    std::string getCallee(){ 
        return Callee;
    }
    
    BaseAST *getArgs(int pos){
        if(i < Args.size())
            return Args.at(i);
        return NULL;
    }
};

