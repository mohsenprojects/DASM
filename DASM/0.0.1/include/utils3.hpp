// functions for know type of oprands and imms.


#pragma once


#include <string>
#include "code_structs.hpp"
#include "utils4.hpp"
#include "lexer.hpp"


bool                             IS_FE(std::string _STR, char _F, char _E);
bool                             IS_IMM(std::string _STR);
bool                             IS_NUM(std::string _STR);

_OPRAND_TYPE                     GET_TYPE(std::string _STR);
_IMM_TYPE                        GET_IMM_TYPE(std::string _STR);
int                              GET_SIZE(std::string D);