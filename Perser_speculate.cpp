
#include "Perser.h"

bool Perser::speculate_Statement(){
    std::cout<<"[log] speculate_statement\n";
    bool success = true;
    mark();
    bool b1 = match(Token::LBRACKET);
    std::cout<<"buf_index1:"<<buf_index<<"\n";
    bool b2 = VariableDecl();              
    std::cout<<"buf_index2:"<<buf_index<<"\n";
    bool b3 = match(Token::RBRACKET);
    std::cout<<"buf_index3:"<<buf_index<<"\n";
    std::cout<<"b1:"<<b1<<" b2:"<<b2<<" b3:"<<b3<<"\n";
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
    std::cout<<"[log]############ speculate_statement result:"<<success<<"\n";
    return success;
}

bool Perser::speculate_VariableDecl(){
    std::cout<<"[log] speculate_variable_decl\n";
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
    std::cout<<"[log]##########  speculate_variable_decl result:"<<success<<"\n";
    return success;
}


