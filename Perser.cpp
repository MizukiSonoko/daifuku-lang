#include "Perser.h"

#include "Token.h"

#include <iostream>
#include <string>
#include <cstdlib>

#include <stdexcept>

using namespace std;

Perser::Perser(std::list<Token> _tokens){
    tokens = _tokens;
    buf_index = 0;
    for(int i=0;i<BUF_MAX;i++){
        nextToken();
    }
    cout<<"[log] perser starts"<<endl;
}

Token Perser::LT(int i){
    return curTokens[(buf_index+i-1)%BUF_MAX];
}

void Perser::match(Token::Type type){
    if(LT(1).getType()==type){
        nextToken();
    }else{
        //TODO
        throw "Error no match ";
    }
}

void Perser::perse(){
    try{
        daifuku();
    }catch(string e){
        cout<<"[Error]"<<e<<endl;
    }catch(const char* e){
        cout<<"[Error]"<<e<<endl; 
    }
}

void Perser::daifuku(){
    cout<<"->[log] daifuku"<<endl;
    match(Token::LPARENT);match(Token::NAME);match(Token::LPARENT);
    if(LT(1).getType()==Token::RPARENT&&LT(2).getType()==Token::COLON){
        cout<<"[log]kawa (o)"<<endl;
        kawa();
    }else if(LT(1).getType()==Token::NAME){
        cout<<"[log]anko O"<<endl;
        anko();
        match(Token::RPARENT);
    }
    match(Token::RPARENT);
    match(Token::SEMICOLON);
    if(LT(1).getType()==Token::FIN){
        cout<<"EOF"<<endl;
    }else{
        daifuku();
    }
}

/*-- TODO --*/
void Perser::kawa(){
    match(Token::RPARENT);

    match(Token::COLON);
    stat();
}
void Perser::anko(){
    stat();
}
/*----------*/

void Perser::stat(){
    cout<<"->[log] stat"<<endl;
    if(LT(1).getType()==Token::NAME){
        match(Token::NAME);
        if(LT(1).getType()==Token::NAME){
            define();
            stat();
        }else if(LT(1).getType()==Token::EQUAL){
            add();
        }
    }else if(LT(1).getType()==Token::LPARENT){
        cout<<"->[log]  ()"<<endl;
        match(Token::LPARENT);
        match(Token::RPARENT);
        match(Token::SEMICOLON);
        stat();
    }
}
void Perser::define(){
    cout<<"->[log]  define"<<endl;
    match(Token::NAME);
    match(Token::SEMICOLON);
}
void Perser::add(){
    cout<<"->[log]  add"<<endl;
    match(Token::EQUAL);
    match(Token::NAME);
    match(Token::OPE_ADD);
    match(Token::NAME);
    match(Token::SEMICOLON);
}

void Perser::nextToken(){
    if(!tokens.empty()){
    //  cout<<"nextToken:"<<tokens.front().getName()<<endl;
        curTokens[buf_index] = tokens.front();
        buf_index = (buf_index + 1)%BUF_MAX;
        tokens.pop_front();
    }else{
        if(buf_index<BUF_MAX){
            buf_index++;
        }else{
            //TODO
            throw "Why file finished? ";
        }
    }
}

