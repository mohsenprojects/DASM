#include "../include/utils4.hpp"


std::string FIL_STR(std::string _STR){
    std::string saver = "";
    
    for(char c : _STR){
        if (c == ';'){
            break;
        } 
        else{
            saver += c;
        }
    }

    return saver;
}

std::string DEL_FE(std::string _STR) {
    if (_STR.length() <= 2) {
        return "";
    }
    return _STR.substr(1, _STR.length() - 2);
}

std::string DEL_F(std::string _STR) {
    if (_STR.length() <= 2) {
        return "";
    }
    return _STR.substr(1, _STR.length() - 1);
}

bool IS_EMPTY(std::string _LINE){
    for (char ch: _LINE){
        if (!std::isspace(static_cast<unsigned char>(ch))){
            return true;
        }
    }
    return false;
}

std::string WO_SPC(std::string _LINE){
    std::string saver = "";
    for(char c : _LINE){
        if (c != ' '){
            saver += c;
        }
    }
    return saver;
}