
#include "Perser.h"
#include "Token.h"
#include "ast/VariableDeclAST.h"

bool Perser::perse(){
    std::cout<<"[log] start perse \n";
    Ast = new TranslationUnitAST();
    while(true){ 
        if(! TranslationUnit()){
            return false;
        }
        if(match(Token::FIN)){
            return true;
        }
    }   
    return false;
}
bool Perser::TranslationUnit(){
    std::cout<<"[log] TranslationUnit\n";
    if(speculate_Statement()){
        std::cout<<"[log] Statement\n";
        match(Token::LBRACKET);
        VariableDecl();       
        match(Token::RBRACKET);
        FunctionStmt();
        return true;
    }
    return false;
}
bool Perser::FunctionStmt(){
    return true;
}
bool Perser::VariableDecl(){
    std::cout<<"[log] VariableDecl\n";
    if(speculate_VariableDecl()){
        std::cout<<"[log] VariableDecl_core\n";
        match(Token::IDENTIFIER);
        match(Token::EQUAL);
        match(Token::NUMBER);
        return true;
    }
    return false;  
//    VariableDeclAST *variableDecl = new VariableDeclAST();   
}



