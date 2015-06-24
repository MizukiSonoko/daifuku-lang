
#include "Ast.h"
#include <string>
#include <vector>

class PrototypeAST : public BaseAST { 
  private:
    std::string Name;
    std::vector<std::string> Params;

  public:
    
    PrototypeAST(std::string &Name,const std::vector<std::string> &params):
        Name(name), Params(params){}

    std::string getName(){ 
        return Name;
    }
    
    std::string getParamName(int i){
        if(i < Params.size()){
            return Params.at(i);
        } else { 
            return NULL;
        }
    }

    int getParamNum(){
        return Params.size();
    }
};

