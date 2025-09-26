// functions for convert types. 


#pragma once


#include <string>
#include <vector>
#include <algorithm>
#include "utils2.hpp"

// SIZE base: BYTE


//convert to littel endian :
std::string                     CONVERT_TO_LIL_ENDIAN(std::string _NUMBER);

// int                             CONVERT_TO_LIL_ENDIAN_INT(std::string _NUMBER);


//convert decimal number  to hexadeciaml : 
std::string                     CONVERT_DEC_TO_HEX(std::string _DECIMAL , int _SIZE);


//convert decimal number to readable number for intel cpus(hex(lilendian(number)))
std::vector<std::string>        CONVERT_DEC_TO_READABLE_INTEL(std::string _DEC);