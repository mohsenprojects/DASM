#include "../include/utils2.hpp"

std::string CONVERT_CHAR_TO_HEX(char _CHAR){
    std::stringstream ss;
    ss << std::hex << std::setw(2) << std::setfill('0') << (int)(unsigned char)_CHAR;
    return ss.str();
}

std::vector<std::string> CONVERT_STRING_TO_HEX(std::string _STR){
    std::vector<std::string> HEX_BYTES;
    for (char c: _STR){
        HEX_BYTES.push_back(CONVERT_CHAR_TO_HEX(c));
    }

    return HEX_BYTES;
}

#define CHECK _DEC==
int CONVERT_HEX_CHAR_TO_DEC_INT(char _DEC) {
    if (CHECK'1')return 1;
    else if (CHECK'2')return 2;
    else if (CHECK'3')return 3;
    else if (CHECK'4')return 4;
    else if (CHECK'5')return 5;
    else if (CHECK'6')return 6;
    else if (CHECK'7')return 7;
    else if (CHECK'8')return 8;
    else if (CHECK'9')return 9;
    else if (CHECK'0')return 0;
    else if (CHECK'a')return 10;
    else if (CHECK'b')return 11;
    else if (CHECK'c')return 12;
    else if (CHECK'd')return 13;
    else if (CHECK'e')return 14;
    else if (CHECK'f')return 15;
    else {
        return -1;
    }
}

char CONVERT_HEX_INT_TO_DEC_CHAR(int _DEC){
    if (CHECK 1)return '1';
    else if (CHECK 2)return '2';
    else if (CHECK 3)return '3';
    else if (CHECK 4)return '4';
    else if (CHECK 5)return '5';
    else if (CHECK 6)return '6';
    else if (CHECK 7)return '7';
    else if (CHECK 8)return '8';
    else if (CHECK 9)return '9';
    else if (CHECK 0)return '0';
    else if (CHECK 10)return 'a';
    else if (CHECK 11)return 'b';
    else if (CHECK 12)return 'c';
    else if (CHECK 13)return 'd';
    else if (CHECK 14)return 'e';
    else if (CHECK 15)return 'f';
    else {
        return 'u';
    }
}

int CONVERT_STRING_HEX_TO_INT(std::string _HEX_) {
    int counter = static_cast<int>(_HEX_.size())-1;
    std::vector<int> H;
    int result = 0;

    for (char c : _HEX_) {
        H.push_back(CONVERT_HEX_CHAR_TO_DEC_INT(c));
    }
    
    for (int ctr : H) {
        int pow = 1;
        for (int i = 1 ; i <= counter; i++) {
            pow *= 16;
        }
        result += ctr * pow;
        counter--;
    }
    return result;
}