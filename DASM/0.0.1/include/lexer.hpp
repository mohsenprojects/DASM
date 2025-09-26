// functions for lexing.


#pragma once


#include <string>
#include <vector>
#include "code_structs.hpp"
#include "utils4.hpp"
#include "utils3.hpp"


LEXED_ASM_CODE                LEXER(std::vector<std::string> _LINE);
std::vector<std::string>      TOKENIZER(std::string _STR);