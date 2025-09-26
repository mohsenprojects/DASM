#include "../include/parser.hpp"


//                                            LEXED_ASM_CODE
//                                            /    / \      \
//                                           /    /   \      \
//                                          /    /     \      \
//                                     VTATX    |      |       VTABS
//                                              |      |
//                                         VTADT       VTARD
//V : VECTOR
//TA : TOKENED ASM ...

// VTATX: ... TEXT : 
                        //std::string CURRENT_LABEL;
                        // int CURRENT_LINE;
                        // std::string _OPCODE="";
                        // std::string _OPRAND1="";
                        // std::string _OPRAND2="";
                        // std::string _OPRAND3="";
                        // std::string _OPRAND4="";    
// VTADT: ... DATA :
                        //std::string _NAME;
                        //int _SIZE;
                        //_IMM_TYPE _DATA_TYPE;
                        //std::string VALUE;
// VTARD: ... RDATA :
                        // std::string _NAME;
                        // int _SIZE;
                        // _IMM_TYPE _DATA_TYPE;
                        // std::string VALUE;
// VTABS: ... BSS :
                        // std::string _NAME;
                        // int _SIZE;

//enum class _IMM_TYPE:
                        // _INT,
                        // _FLOAT,
                        // _CHAR,
                        // _INT_ARRAY,
                        // _FLOAT_ARRAY,
                        // _CHAR_ARRAY,
                        // UNKNOWN,




PARSER_OUTPUT PARSER(LEXED_ASM_CODE LD_CODE){
    PARSER_OUTPUT OUTPUT;
    // data parsing
    for (auto pair : LD_CODE.DATA){
        if (pair._DATA_TYPE == _IMM_TYPE::_INT){
            for (std::string s : CONVERT_DEC_TO_READABLE_INTEL(pair.VALUE)){
                OUTPUT.DATA.push_back(s);
            }
        }
    }

    return OUTPUT;
}