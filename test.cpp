#include "Lexer.h"
#include "Perser.h"

#include <iostream>
#include <unistd.h>

using namespace std;

// TODO use enum.
int debug = 0;

char* option(int argc,char* argv[]){
    int res;
    while((res=getopt(argc, argv,"i:d")) != -1){
        switch(res){
            case 'd':
                debug = 1;
                break;
            case 'i':
                return optarg;
        }
    } 
    return 0;
}

int main(int argc,char* argv[]){
    Lexer*  lexer;    
    Perser* perser;
    char* filename = option(argc, argv);
    if(argc>=2){
        if(debug){
            std::cout<<"Debug option\n";
        }
        lexer = new Lexer(debug);
        std::cout<<"in:"<<filename<<"\n";
        lexer->load(filename);
        if(debug){
            lexer->put_result();
        }
        perser = new Perser(lexer->getTokens(), debug);
        if(perser->perse()){
            std::cout<<"Perse Success!!\n";
        }else{
            std::cout<<"Perse Error!!\n";
        }
    }else{
        cout<<"cook: error: no input files"<<endl;
        return 1;
    }
    RELEASE(lexer);
    RELEASE(perser);
    return 0;
}
