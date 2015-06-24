
#include <vector>
#include "FunctionAST.h"
#include "PrototypeAST.h"

class TranslationUnitAST{
    std::vector<PrototypeAST*> Prototypes;
    std::vector<FunctionAST*>  Functions;

  public:
    TranslationUnitAST(){}
    ~TranslationUnitAST();
    
    void addPrototype(PrototypeAST *prototype);
    void addFunction(FunctionAST *function);

    bool emplt();

    FunctionAST *getFunction(int i){
        if(i < Functions.size()){
            return Functons.at(i);
        }else{
            return NULL;
        }
    }
};
