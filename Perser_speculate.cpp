
#include "Perser.hpp"

bool Perser::speculate_Statement(){
    log("[log] speculate_statement");
    bool success = true;
    if(!(
       match(Token::LBRACKET)&&
       VariableDecl()        &&      
       match(Token::RBRACKET)
    )){
        success = false;
    }
    log("[log] release");
    release();
    log("[log]############ speculate_statement result:"+ std::to_string(success));
    return success;
}

bool Perser::speculate_VariableDecl(){
    log("[log] speculate_variable_decl");
    bool success = true;
    mark();
    if(!(
        match(Token::IDENTIFIER) &&
        match(Token::EQUAL)      && 
        match(Token::NUMBER)
    )){
        success = false;
    }
    release();
    log("[log]##########  speculate_variable_decl result:"+ std::to_string(success));
    return success;
}


