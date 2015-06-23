#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token{
   public:

    enum Type{
        FIN,
        NAME,
        NUMBER,
        IDENTIFIER,
        LPARENT,
        RPARENT,
        RBRACKET,
        LBRACKET,
        SEMICOLON,
        COLON,
        DQUOTATION,
        EQUAL,
        OPE_ADD, 
        COMMA,
        PERIOD,
        BAR,
        RANGLE,
        LANGLE 
   };

    Token(){};
    Token(Type,std::string);
    void setName(std::string);
    void setType(Type);
    std::string getName();
    Type getType();
    std::string getVal();
  private:
    Type type; 
    std::string name;
};

#endif
