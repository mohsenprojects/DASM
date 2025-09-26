#include "../include/lexer.hpp"

LEXED_ASM_CODE LEXER(std::vector<std::string> _LINE){
    CODE_TYPES cd = CODE_TYPES::UNKNOWN;    // code types


    std::vector<TOKENED_ASM_DATA>tad;       //tokened asm data
    std::vector<TOKENED_ASM_TEXT>tat;      // tokende asm text

    LEXED_ASM_CODE RETOBJ;

    for (std::string str : _LINE){
        TOKENED_ASM_DATA ctad;                  // current tokened asm data
        TOKENED_ASM_TEXT ctat;                  // current tokened asm text

        std::vector<std::string> TOKENED_str = TOKENIZER(str); // current str tokens

        if (TOKENED_str.size() == 2 && TOKENED_str[0] == "section"){
            if (TOKENED_str[1] == ".data"){
                cd = CODE_TYPES::DATA;
            }
            else if (TOKENED_str[1] == ".text"){
                cd = CODE_TYPES::TEXT;
            }

            continue;
        }

        // section data:

        
        if (TOKENED_str.size() > 2 && (TOKENED_str[1] == "db" || TOKENED_str[1] == "dW" || TOKENED_str[1] == "dd" || TOKENED_str[1] == "dq")){
            ctad._SIZE = GET_SIZE(TOKENED_str[1]);
        }
    }

}

std::vector<std::string> TOKENIZER(std::string _STR) {
    std::vector<std::string> TK;
    std::string saver;
    bool in_string = false;

    for (char c : _STR) {
        if (c == '\"') {
            if (in_string) {
                if (!saver.empty()) {
                    TK.push_back(saver);
                    saver = "";
                }
                in_string = false;
            }
            else {
                if (!saver.empty()) {
                    TK.push_back(saver);
                    saver = "";
                }
                in_string = true;
            }
        }
        else if (in_string) {
            saver += c;
        }
        else if (c == ' ' || c == ',' || c == '(' || c == ')' || c == '{' || c == '}' || c == ';') {

            if (!saver.empty()) {
                TK.push_back(saver);
                saver = "";
            }

            if (c != ' ') {
                TK.push_back(std::string(1, c));
            }
        }
        else {
            saver += c;
        }
    }

    if (!saver.empty()) {
        TK.push_back(saver);
    }

    return TK;
}