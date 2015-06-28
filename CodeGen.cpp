
#include<llvm/ADT/APInt.h>
#include<llvm/ExecutionEngine/ExecutionEngine.h>
#include<llvm/Linker/Linker.h>
#include<llvm/IR/LLVMContext.h>
#include<llvm/IR/Module.h>
#include<llvm/IR/Metadata.h>
#include<llvm/IR/IRBuilder.h>
#include<llvm/IR/MDBuilder.h>
#include<llvm/IR/ValueSymbolTable.h>

#include <string>
#include "ast/TranslationUnitAST.hpp"

class CodeGen {
  private:
    llvm::Module          *Mod;
    llvm::IRBuilder<> *Builder;

  public:
    CodeGen(){}
    ~CodeGen(){}

    bool codeGen(TranslationUnitAST &ast, std::string name);  
    
};


