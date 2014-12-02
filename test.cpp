#include "Lexer.h"
#include "Perser.h"

#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
    Lexer lexer;    
    if(argc>=2){
        lexer.load(argv[1]);
        lexer.put_result();
    }else{
        cout<<"cook: error: no input files"<<endl;
        return 1;
    }
    Perser perser(lexer.getTokens());
    perser.perse();
    return 0;
}
