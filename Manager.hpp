

#include <iostream>
#include <string>
#include <unistd.h>



#include "Perser.hpp"
#include "Lexer.hpp"
#include "CodeGen.hpp"

#include "ast/TranslationUnitAST.hpp"

class Manager {

    int debug;
    std::string input_file;
    std::string output_file;
    TranslationUnitAST translationUnit;

  public:
    Manager(int argc,char* argv[]): debug(0){
        if(argc == 2){
            input_file = argv[1];
        } else if(argc > 2){
            option(argc, argv);
        } else{
            std::cerr << "cook: no input files"<< std::endl;
        }

        LLVMInitializeNativeTarget();
        llvm::sys::PrintStackTraceOnErrorSignal();
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
        if(!perser->perse()){
            std::cout<<"Perse Error!!\n";
            RELEASE(lexer);
            RELEASE(perser);
            return;
        }
        TranslationUnitAST* ast = perser->getAST();
        CodeGen *codeGen = new CodeGen();
        if(!codeGen->codeGen( ast, input_file)){
            std::cout<<"CodeGen Error!!\n";
            RELEASE(lexer);
            RELEASE(perser);
            return;
        }

        llvm::Module &module = codeGen->getModule();
        if(module.empty()){
            std::cout<<" Module is empty!!\n";
            RELEASE(lexer);
            RELEASE(perser);
            return;
        }

        llvm::PassManager pm;

        pm.add(llvm::createPromoteMemoryToRegisterPass());

        std::error_code error;
        llvm::StringRef out_filename("do.out");
        llvm::raw_fd_ostream raw_stream( out_filename, error, llvm::sys::fs::OpenFlags::F_None );
        pm.add(createPrintModulePass( raw_stream));
        pm.run(module);
        raw_stream.close();
        
        std::cout<<"Complate!!!!\n";
        RELEASE(lexer);
        RELEASE(perser);
    }
}; 
