// functions for read the source files.


#pragma once



#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <cstdint>

std::vector<std::string> F_READER(std::string _FNAME);
bool writeHex(const std::string& filename, const std::string& hex);