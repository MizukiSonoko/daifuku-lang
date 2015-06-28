

#include <iostream>
#include <string>
#include <unistd.h>

#include "Perser.h"
#include "Lexer.h"

class Manager {

    int debug;
    std::string input_file;
    std::string output_file;
  public:
    Manager(int argc,char* argv[]): debug(0){
        if(argc == 2){
            input_file = argv[1];
        } else if(argc > 2){
            option(argc, argv);
        } else{
            std::cerr << "cook: no input files"<< std::endl;
        }
    }
    void option(int argc,char* argv[]){
        int res = 0;
        while((res=getopt(argc, argv,"o:i:d")) != -1){
            switch(res){
                case 'd':
                    debug = 1;
                    break;
                case 'i':
                    input_file = optarg;                    
                    break;
                case 'o':
                    output_file = optarg;
                    break;
            }
        }
    }
    void run(){
        Lexer*  lexer;    
        Perser* perser;
        if(debug){
            std::cout<<"Debug option\n";
        }
        lexer = new Lexer(debug);
        lexer->load(input_file);
        if(debug){
            lexer->put_result();
        }
        perser = new Perser(lexer->getTokens(), debug);
        if(perser->perse()){
            std::cout<<"Perse Success!!\n";
        }else{
            std::cout<<"Perse Error!!\n";
        }
        RELEASE(lexer);
        RELEASE(perser);
    }
}; 
