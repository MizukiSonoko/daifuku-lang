
#include "Token.h"

Token::Token(std::string n,std::string t){
    name = n;
    type = t;
}
void Token::setName(std::string n){
    name = n;
}
void Token::setType(std::string t){
    type = t;
}
std::string Token::getName(){
    return name;
}
std::string Token::getType(){
    return type;
}

