#include "Perser.h"

#include "Token.h"

#include <iostream>
#include <string>
#include <cstdlib>

#include <stdexcept>

using namespace std;

Perser::Perser(std::list<Token> _tokens) : headTokens(0){
    tokens = _tokens;
    buf_index = 0;
    cout<<"[log] perser starts"<<endl;
}

Token Perser::LT(int i){
    cout<<"~[log] LT("<<i<<")"<<endl;
    sync(i);
    cout<<"LT index:"<<buf_index+i-1<<endl;
    return headTokens[buf_index+i-1];
}


bool Perser::spec_object(){
    cout<<"~[log] spec_object"<<endl;
    bool success = true;
    mark();
    try{
        match(Token::NAME);
    }catch(...){
        success = false; 
    } 
    release();
    return success;
}

void Perser::object(){
    match(Token::NAME);
}
void Perser::sync(int i){
    cout<<"~[log] sync("<<i<<")"<<endl;
    cout<<"~~[log] tokens:"<<headTokens.size()<<" buf:"<<buf_index<<endl;
    cout<<"<"<<buf_index +i<<","<<headTokens.size()<<">"<<endl;
    if(buf_index +i  > headTokens.size()  ){
        cout<<"~~[log] buf_index:"<<buf_index<<endl;
        int n = (buf_index + i) - (headTokens.size());
        fill(n);
    }
}
void Perser::fill(int n){
    cout<<"~[log] fill("<<n<<")"<<endl;
    for(int i=0;i<n;i++){
        headTokens.push_back(tokens.front()); 
    }
}
int Perser::mark(){
    cout<<"~[log] mark"<<endl;
    markers.push_back(buf_index);
    return buf_index;    
}
void Perser::release(){
    int marker = markers.front();
    markers.pop_front();
    seek(marker);
}
void Perser::seek(int index){
    buf_index = index;
}
bool Perser::isSpec(){
    return markers.size() > 0;
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
    if(spec_object()){
        cout<<"[log]kawa (o)"<<endl;
    }
}

/*-- TODO --*/
void Perser::kawa(){
}
void Perser::anko(){
}
/*----------*/

void Perser::stat(){
}
void Perser::define(){
}
void Perser::add(){
}

void Perser::nextToken(){
    buf_index++;
    if(buf_index ==headTokens.size() && !isSpec()){
        buf_index = 0;
        headTokens.clear(); 
    }
    sync(1);
}

