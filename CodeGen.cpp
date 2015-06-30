
#include "CodeGen.hpp"


CodeGen::CodeGen(){
    builder = new llvm::IRBuilder<>(llvm::getGlobalContext());
    module = nullptr;
}

CodeGen::~CodeGen(){
    RELEASE(builder);
    RELEASE(module);
}

bool CodeGen::codeGen(TranslationUnitAST &ast, std::string name){
    if(!genTranslationUnit( ast, name)){
        return false;
    }
    return true;
}

bool CodeGen::genTranslationUnit( TranslationUnitAST ast, std::string name){
    module = new llvm::Module( name, llvm::getGlobalContext());
    llvm::Value *value = nullptr;
    VariableDeclAST *vast;
    for(int i=0; i <  ast.getValiableDeclsize(); i++){
        vast = llvm::dyn_cast<VariableDeclAST>( ast.getVariableDecl(i)); 
        value = genVariableDecl( vast);
    }
    return true;
}

llvm::Value *CodeGen::genVariableDecl( VariableDeclAST *ast){
    llvm::AllocaInst *alloca = builder -> CreateAlloca(
        llvm::Type::getInt32Ty( llvm::getGlobalContext()),
        0,
        ast -> getName()
    );
    return alloca;
}

