#include "Lexer.h"
#include "Perser.h"

#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
    Lexer lexer;    
    Perser* perser;
    if(argc>=2){
        lexer.load(argv[1]);
        lexer.put_result();
        perser = new Perser(lexer.getTokens());
        if(perser->perse()){
            std::cout<<"Perse Success!!\n";
        }else{
            std::cout<<"Perse Error!!\n";
        }
    }else{
        cout<<"cook: error: no input files"<<endl;
        return 1;
    }
    RELEASE(perser);
    return 0;
}
