
#include "Perser.h"

bool Perser::speculate_Statement(){
    log("[log] speculate_statement");
    bool success = true;
    mark();
    bool b1 = match(Token::LBRACKET);
    log("buf_index1:"+ std::to_string(buf_index));
    bool b2 = VariableDecl();              
    log("buf_index2:"+ std::to_string(buf_index));
    bool b3 = match(Token::RBRACKET);
    log("buf_index3:"+ std::to_string(buf_index));
    log("b1:"+ std::to_string(b1) +" b2:"+ std::to_string(b2) +" b3:"+ std::to_string(b3));
    if(!(b1&&b2&&b3)){
   /* if(!(
       match(Token::LBRACKET)&&
       VariableDecl()        &&      
       match(Token::RBRACKET)
    )){
   */
        success = false;
    }
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


