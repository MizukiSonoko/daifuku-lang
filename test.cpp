#include "Lexer.h"

#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
    if(argc>=2){
        Lexer lexer(argv[1]);
        lexer.put_result();
    }else{
        cout<<"cook: error: no input files"<<endl;
        return 1;
    }
    return 0;
}
