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
#include<llvm/Support/Signals.h>
#include<llvm/PassManager.h>
#include<llvm/Support/Signals.h>
#include<llvm/Support/raw_ostream.h>
#include<llvm/Transforms/Scalar.h>

#include <iostream>
#include <string>
#include "ast/TranslationUnitAST.hpp"
#include "ast/BinaryExprAST.hpp"
#include "ast/VariableAST.hpp"

class CodeGen {
  private:
    llvm::Module          *module;
    llvm::IRBuilder<>    *builder;

    int debug;
    void log(std::string);
  public:
    CodeGen(int debug);
    ~CodeGen();

    llvm::Module &getModule();

    bool codeGen(TranslationUnitAST *ast, std::string name);  
    bool genTranslationUnit( TranslationUnitAST *ast, std::string name);
    llvm::Value *genVariableDecl( VariableDeclAST *ast);
    llvm::Value *genBinaryExpr( BinaryExprAST *ast);
};

#endif
