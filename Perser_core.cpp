#include "Perser.hpp"

#include "Token.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

#include <stdexcept>


Perser::Perser(std::list<Token> _tokens, int _debug){
    tokens = _tokens;
    debug  = _debug; 
    buf_index = 0;
    curString ="";
    log("[log] perser starts");
}
void Perser::log(std::string s){
    if(debug){
        std::cout<< s << std::endl;
    }
}
TranslationUnitAST* Perser::getAST(){
    if(Ast != NULL){
        return Ast;
    }
    return NULL;
}
 
Token Perser::LT(int i){
    log("~[log] LT("+ std::to_string(i) +")");
    sync(i);
    log("~LT buf_index:"+ std::to_string(buf_index) );
    log("~LT index:"+ std::to_string(buf_index+i-1) +" val:"+ headTokens[buf_index+i-1].getName());
    return headTokens[buf_index+i-1];
}

void Perser::sync(int i){
    log("~[log] sync("+ std::to_string(i) +")");
    log("~~[log] tokens:"+ std::to_string(headTokens.size()) +" buf:"+ std::to_string(buf_index));
    if(buf_index + i > headTokens.size()){
        log("~~~[log] buf_index:"+ std::to_string(buf_index));
        int n = (buf_index + i) - (headTokens.size());
        fill(n);
    }
}
void Perser::fill(int n){
    log("~~~~[log] fill("+ std::to_string(n) +")");
    for(int i=0;i < n;i++){
        log("~~~~~[log] fill insert val:"+ tokens.front().getName());
        headTokens.push_back(tokens.front());
        tokens.pop_front();
    }
}
int Perser::mark(){
    log("~[log] mark buf:"+ std::to_string(buf_index));
    markers.push(buf_index);
    return buf_index;    
}
void Perser::release(){
    log("~[log] release()");
    if(!markers.empty()){
        int marker = markers.top();
        markers.pop();
        log("[log] release maker:"+ std::to_string(marker));
        seek(marker);
    }
}
void Perser::seek(int index){
    log(" [log] seek:"+ std::to_string(index));
    buf_index = index;
}
bool Perser::isSpec(){
    return markers.size() > 0;
}

bool Perser::match(Token::Type type){
    Token  token =  LT(1);
     
    curString = token.getName();
    Token::Type t = token.getType();
    
    log("[log] match <R:"+ std::to_string(t) +",P:"+ std::to_string(type) +">");  
    if(type==t){//LT(1).getType()){
        log("[log] True");
        nextToken();
        log("[log] return true");
        return true;
    }else{
        log("[log] False");
        return false;
    }
}
bool Perser::nextToken(){
    log("~[log] nextToken");
    buf_index++;
    if(buf_index == headTokens.size() && !isSpec()){
        log("[log] last");
        buf_index = 0;
        headTokens.clear();
        return false; 
    }
    sync(1);   
    return true;
}

