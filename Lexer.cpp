#include "Lexer.h"

#include <fstream>
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

void Lexer::load(char* filename){
    ifs.open(filename);
    if(!ifs){
        cout<<"cook: error: no such file or directory: '"<<filename<<"'\n";
    }
    
    cout<<"[log]start analys\n";
    analyze();
}
Lexer::~Lexer(){
    ifs.close();
}

void Lexer::analyze(){
    istreambuf_iterator<char> it(ifs);
    istreambuf_iterator<char> last;
    string data(it, last);  
    for(int i=0;i<data.size();){
        switch(data[i]){
            case ' ': case '\t':
            case '\n':case '\r':
                i++;
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
            default:
                if(isLetter(data[i])){
                    string buffer = "";
                    do{
                        buffer += data[i];
                        i++;
                    }while(isLetter(data[i]));
                    tokens.push_back(Token(Token::NAME,buffer));
                    i--;
                }else{
                    cout<<"Error! invalid charator:"<<data[i]<<endl;
                    return;
                }
        }
        i++;
    }
    tokens.push_back(Token(Token::FIN,"<EOF>"));
}
bool Lexer::isLetter(char c){
    if((c>='a'&&c<='z')||
       (c>='A'&&c<='Z'))
        return true;
    return false;
}

list<Token> Lexer::getTokens(){
    return tokens;
}

void Lexer::put_result(){

    list<Token>::iterator it = tokens.begin();
    while(it!=tokens.end()){
        cout<<(*it).getVal()<<endl;
        it++;
    }
}


