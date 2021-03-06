#include "Lexer.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <iterator>

void Lexer::load(std::string filename){

    reg_special = std::regex(R"(\W+)");
    reg_number =  std::regex(R"([0-9]+)");
    reg_letter =  std::regex(R"([\w]+)");

    ifs.open(filename);
    if(!ifs){
        std::cout<<"cook: error: no such file or directory: '"<<filename<<"'\n";
    }
    log("[log]start analys");
    analyze();
}
Lexer::~Lexer(){
    ifs.close();
}
void Lexer::log(std::string str){
    if(debug){
        std::cout<<str<<"\n";
    }
}

void Lexer::analyze(){
    std::istreambuf_iterator<char> it(ifs);
    std::istreambuf_iterator<char> last;
    std::string data(it, last); 
    std::string buffer = ""; 

    for(int i=0;i<data.size();i++){

        if(isLetter(data[i]) || isNumber(data[i])){
            buffer += data[i];
            continue;
        } else if(!buffer.empty()){

            if(isNumber(buffer)){
                log("[log] lexer insert(1) type:"+ std::to_string(Token::NUMBER) +","+ buffer);
                tokens.push_back(Token(Token::NUMBER,buffer));
            } else {
                log("[log] lexer insert(1) type:"+ std::to_string(Token::IDENTIFIER) +","+ buffer);
                tokens.push_back(Token(Token::IDENTIFIER,  buffer));
            }
            buffer.clear();
        }

        switch(data[i]){
            case  ' ': case '\t':
            case '\n': case '\r':
                continue;
            case '(':
                tokens.push_back(Token(Token::LPARENT,"("));
                break;
            case ')':
                tokens.push_back(Token(Token::RPARENT,")"));
                break;
            case ']':
                tokens.push_back(Token(Token::RBRACKET,"]"));
                break;
            case '[':
                tokens.push_back(Token(Token::LBRACKET,"["));
                break;
            case '<':
                tokens.push_back(Token(Token::LANGLE,"<"));
                break;
            case '>':
                tokens.push_back(Token(Token::RANGLE,">"));
                break;
            case ';':
                tokens.push_back(Token(Token::SEMICOLON,";"));
                break;
            case ':':
                tokens.push_back(Token(Token::COLON,":"));
                break;
            case '"':
                tokens.push_back(Token(Token::DQUOTATION,"\""));
                break;
            case '=':
                tokens.push_back(Token(Token::EQUAL,"="));
                break;
            case '+':
                tokens.push_back(Token(Token::OPE_ADD,"+"));
                break;
            case '-':
                tokens.push_back(Token(Token::BAR,"-"));
                break;
            case '.':
                tokens.push_back(Token(Token::PERIOD,"."));
                break;
            case ',':
                tokens.push_back(Token(Token::COMMA,","));
                break;
            default:
                if(!buffer.empty()){
                    if(isNumber(buffer[i])){
                        log("[log] lexer insert(2) type:"+ std::to_string(Token::NUMBER) +","+ buffer);
                        tokens.push_back(Token(Token::NUMBER,buffer));
                    } else {
                        log("[log] lexer insert(2) type:"+ std::to_string(Token::IDENTIFIER) +","+ buffer);
                        tokens.push_back(Token(Token::IDENTIFIER,  buffer));
                    }
                    buffer.clear();
                }else{
                    std::cout<<"Error! invalid charator:"<<data[i]<<std::endl;
                    return;
                }
        }
    }
    tokens.push_back(Token(Token::FIN,"<EOF>"));
}
bool Lexer::isLetter(char c){
    std::string str({c});
    if(std::regex_match( str, reg_letter)){
        return true;
    }
    return false;
}
bool Lexer::isNumber(std::string s){
    if(std::regex_match( s, reg_number)){
        return true;
    }
    return false;
}
bool Lexer::isNumber(char c){
    std::string str({c});
    if(std::regex_match( str, reg_number)){
        return true;
    }
    return false;
}
std::list<Token> Lexer::getTokens(){
    return tokens;
}

void Lexer::put_result(){

    std::list<Token>::iterator it = tokens.begin();
    while(it!=tokens.end()){
        std::cout<<(*it)<<std::endl;
        it++;
    }
}


