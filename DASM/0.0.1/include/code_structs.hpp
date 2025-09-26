// struct and enum classs for code or line.


#pragma once


enum class _CODE_TYPE{

                        _DATA,
                        _TEXT,
                        _BSS,
                        _RODATA,

};

enum class _IMM_TYPE{

                        _INT,
                        _FLOAT,
                        _CHAR,
                        _INT_ARRAY,
                        _FLOAT_ARRAY,
                        _CHAR_ARRAY,
                        UNKNOWN,

};

enum class _OPRAND_TYPE{

                        _REG,
                        _IMM,
                        _ABS_ADRESS,
                        _REGADDRES,
                        UNKNOWN,

};

enum class CODE_TYPES{

                        TEXT,
                        DATA,
                        BSS,
                        RDATA,
                        OTHER,
                        UNKNOWN

};


//qmov $rax, imm64
//
//
//opcode, oprand1, oprand2, oprand3, oprand4
//._OPCODE="qmov", ._OPRAND1="$rax", ._OPRAND2="imm64"

struct TOKENED_ASM_TEXT{

                        std::string CURRENT_LABEL;
                        int CURRENT_LINE;
                        std::string _OPCODE="";
                        std::string _OPRAND1="";
                        std::string _OPRAND2="";
                        std::string _OPRAND3="";
                        std::string _OPRAND4="";

};

//name dw 10
//._NAME=name, ._SIZE=4, ._LIL_ENDIAN_VALUE={0X10, 0X00, 0X00, 0X00}, _DATA_TYPE=_TYPE::_INT

struct TOKENED_ASM_DATA{

                        std::string _NAME;
                        int _SIZE;
                        _IMM_TYPE _DATA_TYPE;
                        std::string VALUE;

};

struct TOKENED_ASM_RDATA{
                        std::string _NAME;
                        int _SIZE;
                        _IMM_TYPE _DATA_TYPE;
                        std::string VALUE;
};

struct TOKENED_ASM_BSS{
                        std::string _NAME;
                        int _SIZE;
};

struct LEXED_ASM_CODE{

                        std::vector<TOKENED_ASM_DATA> DATA;
                        std::vector<TOKENED_ASM_RDATA> RDATA;
                        std::vector<TOKENED_ASM_BSS> BSS;
                        std::vector<TOKENED_ASM_TEXT> TEXT;
                        
};


struct LABELS{

    std::string name;
    std::vector<TOKENED_ASM_TEXT> CODES;

};


struct PARSER_OUTPUT{
    std::vector<std::string> DATA;
    std::vector<std::string> RDATA;
    std::vector<std::string> BSS;
    std::vector<std::string> TEXT;
};