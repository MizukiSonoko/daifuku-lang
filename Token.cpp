
#include "Token.h"
#include <string>

Token::Token(Token::Type t,std::string n){
    name = n;
    type = t;
}
void Token::setName(std::string n){
    name = n;
}
void Token::setType(Type t){
    type = t;
}
std::string Token::getName(){
    return name;
}
Token::Type Token::getType(){
    return type;
}
std::string Token::getVal(){
    return "<"+name+">";
}

