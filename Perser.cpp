
#include "Perser.h"
#include "Token.h"
#include "ast/VariableDeclAST.h"

bool Perser::perse(){
    log("[log] start perse");
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
    log("[log] TranslationUnit");
    if(speculate_Statement()){
        log("[log] Statement");
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
    log("[log] VariableDecl");
    if(speculate_VariableDecl()){
        log("[log] VariableDecl_core");
        match(Token::IDENTIFIER);
        log("[log] "+curString);
        match(Token::EQUAL);
        match(Token::NUMBER);
        return true;
    }
    return false;  
//    VariableDeclAST *variableDecl = new VariableDeclAST();   
}



