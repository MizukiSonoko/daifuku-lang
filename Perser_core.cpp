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
    cout<<"[log] perser starts"<<endl;
}

Token Perser::LT(int i){
    cout<<"~[log] LT("<<i<<")"<<endl;
    sync(i);
    cout<<"~LT buf_index:"<<buf_index<<"\n";
    cout<<"~LT index:"<<buf_index+i-1<<" val:"<<headTokens[buf_index+i-1]<<"\n";
    return headTokens[buf_index+i-1];
}

void Perser::sync(int i){
    cout<<"~[log] sync("<<i<<")\n";
    cout<<"~~[log] tokens:"<<headTokens.size()<<" buf:"<<buf_index<<"\n";
    if(buf_index + i > headTokens.size()){
        cout<<"~~~[log] buf_index:"<<buf_index<<"\n";
        int n = (buf_index + i) - (headTokens.size());
        fill(n);
    }
}
void Perser::fill(int n){
    cout<<"~~~~[log] fill("<<n<<")\n";
    for(int i=0;i < n;i++){
        std::cout<<"~~~~~[log] fill insert val:"<<tokens.front()<<"\n";
        headTokens.push_back(tokens.front());
        tokens.pop_front();
    }
}
int Perser::mark(){
    cout<<"~[log] mark buf:"<<buf_index<<endl;
    markers.push(buf_index);
    return buf_index;    
}
void Perser::release(){
    int marker = markers.top();
    markers.pop();
    cout<<"[log] release maker:"<<marker<<endl;
    seek(marker);
}
void Perser::seek(int index){
    std::cout<<" [log] seek:"<<index<<"\n";
    buf_index = index;
}
bool Perser::isSpec(){
    return markers.size() > 0;
}

bool Perser::match(Token::Type type){
    Token::Type t = LT(1).getType();
    std::cout<<"[log] match <R:"<<t<<",P:"<<type<<">\n";  
    if(type==t){//LT(1).getType()){
        std::cout<<"[log] True\n";
        nextToken();
        return true;
    }else{
        std::cout<<"[log] False\n";
        return false;
    }
}
void Perser::nextToken(){
    std::cout<<"~[log] nextToken buf_index:"<<buf_index+1<<"\n";
    buf_index++;
    if(buf_index == headTokens.size() && !isSpec()){
        std::cout<< "[log] last"<<std::endl;
        buf_index = 0;
        headTokens.clear(); 
    }else{
        sync(1);
    }
}

