#include "../include/freader.hpp"



std::vector<std::string> F_READER(std::string _FNAME){
    std::fstream file(_FNAME, std::ios::in);
    std::string line;

    std::vector<std::string>lines;

    if (file.is_open()){
        while (std::getline(file, line)){
            lines.push_back(line);
        } 
    } else {
        std::cout<<"error in open file!.";
    }

    return lines;
}

bool writeHex(const std::string& filename, const std::string& hex) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) return false;
    
    std::string clean;
    for (char c : hex) if (c != ' ') clean += c;
    
    if (clean.length() % 2 != 0) return false;
    
    for (size_t i = 0; i < clean.length(); i += 2) {
        auto charToVal = [](char c) -> int {
            if (c >= '0' && c <= '9') return c - '0';
            if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
            if (c >= 'a' && c <= 'f') return 10 + (c - 'a');
            return -1;
        };
        
        int h = charToVal(clean[i]);
        int l = charToVal(clean[i+1]);
        if (h == -1 || l == -1) return false;
        
        uint8_t byte1 = (h << 4) | l;
        file.write((char*)&byte1, 1);
    }
    
    return true;
}