#ifndef CODE_GEN
#define CODE_GEN

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
#include "ast/BinaryExprAST.hpp"
#include "ast/VariableAST.hpp"

class CodeGen {
  private:
    llvm::Module          *module;
    llvm::IRBuilder<>    *builder;

  public:
    CodeGen();
    ~CodeGen();


    bool codeGen(TranslationUnitAST *ast, std::string name);  
    bool genTranslationUnit( TranslationUnitAST *ast, std::string name);
    llvm::Value *genVariableDecl( VariableDeclAST *ast);
    llvm::Value *genBinaryExpr( BinaryExprAST *ast);
};

#endif
