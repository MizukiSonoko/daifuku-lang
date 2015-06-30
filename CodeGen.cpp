
#include "CodeGen.hpp"


CodeGen::CodeGen(){
    builder = new llvm::IRBuilder<>(llvm::getGlobalContext());
    module = nullptr;
}

CodeGen::~CodeGen(){
    RELEASE(builder);
    RELEASE(module);
}

bool CodeGen::codeGen(TranslationUnitAST *ast, std::string name){
    if(!genTranslationUnit( ast, name)){
        return false;
    }
    return true;
}

bool CodeGen::genTranslationUnit( TranslationUnitAST *ast, std::string name){
    module = new llvm::Module( name, llvm::getGlobalContext());
    llvm::Value *value = nullptr;
    VariableDeclAST *vast;
    for(int i=0; i <  ast->getValiableDeclsize(); i++){
        vast = llvm::dyn_cast<VariableDeclAST>( ast->getVariableDecl(i)); 
        value = genVariableDecl( vast);
    }
    BinaryExprAST* expr;
    for(int i=0; i <  ast->getBinaryExprSize(); i++){
        expr = llvm::dyn_cast<BinaryExprAST>( ast->getBinaryExpr(i)); 
        value = genBinaryExpr(expr);
    }

    return true;
}
llvm::Value *CodeGen::genBinaryExpr( BinaryExprAST *ast){
    BaseAST *lhs = ast -> getLHS();
    BaseAST *rhs = ast -> getRHS();

    llvm::Value *lhs_v;
    llvm::Value *rhs_v;

    if(ast -> getOp() == "="){
        VariableAST *lhs_value = llvm::dyn_cast<VariableAST>( lhs );
    }
}

llvm::Value *CodeGen::genVariableDecl( VariableDeclAST *ast){
    llvm::AllocaInst *alloca = builder -> CreateAlloca(
        llvm::Type::getInt32Ty( llvm::getGlobalContext()),
        0,
        ast -> getName()
    );
    return alloca;
}

