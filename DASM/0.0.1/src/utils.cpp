#include "../include/utils.hpp"

std::string CONVERT_TO_LIL_ENDIAN(std::string _NUMBER){
    std::string H;
    std::vector<std::string> BYTES;

    
    int f = 1;
    std::string BYTE = "";
    for (char c : _NUMBER){
        if (f == 1){
            BYTE += c;
            f += 1;
        }
        else if (f == 2){
            BYTE += c;
            f = 1;
            BYTES.push_back(BYTE);
            BYTE = "";
        }
    }
    std::reverse(BYTES.begin(), BYTES.end());

    for (std::string c : BYTES){
        H += c;
    }

    return H;
}

std::string CONVERT_DEC_TO_HEX(std::string _DECIMAL, int _SIZE){
    int DEC = std::stoi(_DECIMAL);
    std::string res = "";
    while (true){
        char local_saver = CONVERT_HEX_INT_TO_DEC_CHAR(DEC % 16);
        res += local_saver;
        DEC /= 16;
        if  (DEC <= 1) break;
    }
    std::reverse(res.begin(), res.end());
    if (res.size()>_SIZE*2){
        return "size is wrong";
    }
    else if (res.size()==_SIZE*2){
        return res;
    }
    else if (res.size()<_SIZE*2){
        std::string zeros ;
        for (int i = 1; i <= _SIZE*2-res.size(); i ++){
            zeros += "0";
        }
        return zeros+res;
    }    
}

std::vector<std::string> CONVERT_DEC_TO_READABLE_INTEL(std::string _DEC, int _SIZE){
    std::string S = CONVERT_TO_LIL_ENDIAN(CONVERT_DEC_TO_HEX(_DEC, _SIZE));
    std::vector<std::string> R;
    bool in = false;
    std::string lsaver = "";
    for (char c : S){
        if (!in){
            lsaver += c;
            in = true;
        }
        else if (in){
            lsaver += c;
            R.push_back(lsaver);
            lsaver = "";
            in = false;
        }
    }

    return R;
}