// functions for convert types(2).


#pragma once


#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

std::string                         CONVERT_CHAR_TO_HEX(char _CHAR);
std::vector<std::string>            CONVERT_STRING_TO_HEX(std::string _STR);


int                                 CONVERT_HEX_CHAR_TO_DEC_INT(char _DEC);
char                                CONVERT_HEX_INT_TO_DEC_CHAR(int _DEC);
int                                 CONVERT_STRING_TO_HEX_INT(std::string _HEX_);