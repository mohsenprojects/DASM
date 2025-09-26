#include "../include/utils3.hpp"






bool IS_FE(std::string _STR, char _F, char _E) {
    if (_STR.size() <= 1) {
        return false;
    }
    else if (_E != 'x') {
        if (_STR[0] == _F && _STR[_STR.size() - 1] == _E) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (_E == 'x') {
        if (_STR[0] == _F) {
            return true;
        }
        else {
            return false;
        }
    }
}

bool IS_IMM(std::string _STR){
    return IS_FE(_STR, '$', 'x');
}

bool IS_NUM(std::string _STR, std::string _CHS) {
    bool r;
    for (char c : _STR) {
        for (char co : _CHS) {
            if (c != co) {
                r = false;
            }
            else {
                r = true;
                break;
            }
        }
        if (r == false) {
            break;
        }
    }
    return r;
}








_OPRAND_TYPE GET_TYPE(std::string _STR){
    if (IS_FE(_STR, '%', 'x')){
        return _OPRAND_TYPE::_REG;
    }
    else if (IS_FE(_STR, '$', 'x')){
        return _OPRAND_TYPE::_IMM;
    }
    else if (IS_FE(_STR, '[', ']')){
        return _OPRAND_TYPE::_ABS_ADRESS;
    }
    else if (IS_FE(_STR, '(', ')')){
        return _OPRAND_TYPE::_REGADDRES;
    }
    else{
        return _OPRAND_TYPE::UNKNOWN;
    }
}

// %rax -> reg
// $12345 -> imm
// [ram] -> ram(abs adressing)
// (rcx) -> ram(reg adressing)

// input example : $1332
//                 ${31, 3324, 5213}
_IMM_TYPE GET_IMM_TYPE(std::string _STR){
    _IMM_TYPE IMM = _IMM_TYPE::UNKNOWN; 

    if (_STR[0] != '$'){
        return IMM;
    }
    _STR = DEL_F(_STR);
    
    // _INT
    for (char c : _STR){
        if(c != '1' && c != '2' && c != '3'
            && c != '4' && c != '5' && c != '6' 
            && c != '7' && c != '8'&& c != '9'
            && c != '0'){
            IMM = _IMM_TYPE::UNKNOWN;
            break;
        }
        else{
            IMM = _IMM_TYPE::_INT;
        }
    }

    if (IMM == _IMM_TYPE::_INT){
        return IMM;
    }


    // _FLOAT
    for (char c : _STR){
        if(c != '1' && c != '2' && c != '3'
            && c != '4' && c != '5' && c != '6' 
            && c != '7' && c != '8'&& c != '9'
            && c != '0' && c != '.'){
            IMM = _IMM_TYPE::UNKNOWN;
            break;
        }
        else{
            IMM = _IMM_TYPE::_FLOAT;
        }
    }

    if (IMM == _IMM_TYPE::_FLOAT){
        return IMM;
    }


    // _CHAR
    if (_STR.size() != 3){
        IMM = _IMM_TYPE::UNKNOWN;
    }
    else if (_STR[0] == '\'' && _STR[_STR.size()-1] == '\'' && _STR.size()==3){
        IMM = _IMM_TYPE::_FLOAT;
    }

    if (IMM == _IMM_TYPE::_CHAR){
        return IMM;
    }


    // _INT_ARRAY
    if (IS_FE(_STR, '{', '}')){
        std::vector<std::string> vec = TOKENIZER(_STR);
        IMM = _IMM_TYPE::_INT_ARRAY;
        for (std::string str: vec){
            if (!IS_NUM(_STR, "0123456789")){
                IMM = _IMM_TYPE::UNKNOWN;
                break;
            }
        }
    }

    if (IMM == _IMM_TYPE::_INT_ARRAY){
        return IMM;
    }

    // FLOAT ARR
    if (IS_FE(_STR, '{', '}')){
        std::vector<std::string> vec = TOKENIZER(_STR);
        IMM = _IMM_TYPE::_INT_ARRAY;
        for (std::string str: vec){
            if (!IS_NUM(_STR, "0123456789.")){
                IMM = _IMM_TYPE::UNKNOWN;
                break;
            }
        }
    }

    if (IMM == _IMM_TYPE::_INT_ARRAY){
        return IMM;
    }

    // CHAR ARR
    if (IS_FE(_STR, '{', '}')){
        std::string s = DEL_FE(_STR);
        if (IS_FE(_STR, '\"', '\"')){
            IMM = _IMM_TYPE::_CHAR_ARRAY;
        }
    }
    
    if (IMM == _IMM_TYPE::_CHAR_ARRAY) {
        return IMM;
    }

    // return IMM ;
}



int GET_SIZE(std::string D){
    if (D == "db"){
        return 1; 
    }
    else if (D == "dw"){
        return 2;
    }
    else if (D == "dd"){
        return 4;
    }
    else if (D == "dq"){
        return 8;
    }
    else {
        return 0;
    }
}