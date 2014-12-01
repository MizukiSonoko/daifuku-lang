#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token{
    std::string name;
    //後々stringから変更する。prototype
    std::string type;
   public:
    Token(std::string,std::string);
    void setName(std::string);
    void setType(std::string);
    std::string getName();
    std::string getType();
};

#endif
