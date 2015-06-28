#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <ostream>

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
  private:
    friend std::ostream& operator<<(std::ostream& os,Token& token);  
    friend std::ostream& operator<<(std::ostream& os,const Token& token);  

    Type type; 
    std::string name;
};

#endif
