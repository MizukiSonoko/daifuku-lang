#include "Lexer.h"

#include <fstream>
#include <iostream>
#include <string>
#include <iterator>

void Lexer::load(char* filename){
    ifs.open(filename);
    if(!ifs){
        std::cout<<"cook: error: no such file or directory: '"<<filename<<"'\n";
    }
    
    std::cout<<"[log]start analys\n";
    analyze();
}
Lexer::~Lexer(){
    ifs.close();
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
            if(isNumber(buffer[i])){
                tokens.push_back(Token(Token::NUMBER,buffer));
            } else {
                tokens.push_back(Token(Token::NAME,  buffer));
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
                        tokens.push_back(Token(Token::NUMBER,buffer));
                    } else {
                        tokens.push_back(Token(Token::NAME,  buffer));
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
    if((c>='a'&&c<='z')||
       (c>='A'&&c<='Z')||
       (c=='!'||c=='#'))
        return true;
    return false;
}
bool Lexer::isNumber(char c){
    if(c>='0'&&c<='9')
        return true;
    return false;
}
std::list<Token> Lexer::getTokens(){
    return tokens;
}

void Lexer::put_result(){

    std::list<Token>::iterator it = tokens.begin();
    while(it!=tokens.end()){
        std::cout<<(*it).getVal()<<std::endl;
        it++;
    }
}


