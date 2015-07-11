#include "Manager.hpp"

#include <iostream>

#include "Perser.hpp"
#include "Lexer.hpp"
#include "CodeGen.hpp"

using namespace std;

int main(int argc,char* argv[]){
    Manager m(argc, argv);
    m.run();
    return 0;
}

