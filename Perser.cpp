
#include "Perser.hpp"
#include "Token.hpp"
#include "ast/VariableDeclAST.hpp"

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
        std::string _identifier = curString;
        log("[log] "+curString);
        VariableTable.push_back(curString);

        match(Token::EQUAL);
        match(Token::NUMBER);
        int _value = std::stoi(curString);
        VariableDeclAST* variableDeclAst = new VariableDeclAST(_identifier, _value);
        Ast->addVariableDecl(variableDeclAst);
        return true;
    }
    return false;  
}



