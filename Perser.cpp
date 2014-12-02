#include "Perser.h"

#include <iostream>
#include <string>
#include <cstdlib>

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

void Perser::match(string type){
    //cout<<"match("<<type<<","<<LT(1).getType()<<"("<<LT(1).getName()<<"))"<<endl;
    if(LT(1).getType()==type){
        nextToken();
    }else{
        throw "Error no match '"+type+"'";
    }
}

void Perser::perse(){
    try{
        daifuku();
    }catch(string e){
        cout<<"[Error]"<<e<<endl;
    }
}

void Perser::daifuku(){
    cout<<"->[log] daifuku"<<endl;
    match("LPARENT");match("NAME");match("LPARENT");
    if(LT(1).getType()=="RPARENT"&&LT(2).getType()=="COLON"){
        cout<<"[log]kawa (o)"<<endl;
        kawa();
    }else if(LT(1).getType()=="NAME"){
        cout<<"[log]anko O"<<endl;
        anko();
        match("RPARENT");
    }
    match("RPARENT");
    match("SEMICOLON");
    if(LT(1).getType()=="EOF"){
        cout<<"EOF"<<endl;
    }else{
        daifuku();
    }
}

/*-- TODO --*/
void Perser::kawa(){
    match("RPARENT");
    match("COLON");
    stat();
}
void Perser::anko(){
    stat();
}
/*----------*/

void Perser::stat(){
    cout<<"->[log] stat"<<endl;
    if(LT(1).getType()=="NAME"){
        match("NAME");
        if(LT(1).getType()=="NAME"){
            define();
            stat();
        }else if(LT(1).getType()=="EQUAL"){
            add();
        }
    }else if(LT(1).getType()=="LPARENT"){
        cout<<"->[log]  ()"<<endl;
        match("LPARENT");
        match("RPARENT");
        match("SEMICOLON");
        stat();
    }
}
void Perser::define(){
    cout<<"->[log]  define"<<endl;
    match("NAME");
    match("SEMICOLON");
}
void Perser::add(){
    cout<<"->[log]  add"<<endl;
    match("EQUAL");
    match("NAME");
    match("OPE_ADD");
    match("NAME");
    match("SEMICOLON");
}

void Perser::nextToken(){
    if(!tokens.empty()){
        //cout<<"nextToken:"<<tokens.front().getType()<<endl;
        curTokens[buf_index] = tokens.front();
        buf_index = (buf_index + 1)%BUF_MAX;
        tokens.pop_front();
    }else{
        if(buf_index<BUF_MAX){
            buf_index++;
        }else{
            throw "Why file finished? ["+curTokens[0].getType()+"]";
        }
    }
}

