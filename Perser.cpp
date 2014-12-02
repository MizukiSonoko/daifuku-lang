#include "Perser.h"

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

Perser::Perser(std::list<Token> _tokens){
    tokens = _tokens;
    curToken = tokens.front();
    tokens.pop_front();
 
    cout<<"[log] perser starts"<<endl;
}

void Perser::match(string type){
    if(curToken.getType()==type){
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
    if(curToken.getType()=="RPARENT"){
        cout<<"[log]kawa (o)"<<endl;
        kawa();
    }else if(curToken.getType()=="NAME"){
        cout<<"[log]anko O"<<endl;
        anko();
    }
    match("RPARENT");
    match("SEMICOLON");
    if(curToken.getType()=="EOF"){
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
    if(curToken.getType()=="NAME"){
        match("NAME");
        if(curToken.getType()=="NAME"){
            define();
            stat();
        }else if(curToken.getType()=="EQUAL"){
            add();
        }
    }else if(curToken.getType()=="LPARENT"){
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
        curToken = tokens.front();
        tokens.pop_front();
    }else{
        cout<<"[log] successful!"<<endl;
        exit(0);
    }
}

