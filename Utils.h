#pragma once
#include <string>
#include <vector>


//Trims leading and trailing spaces from a string.
std::string trim(const std::string& s);

/*
Tokenizes a string.
Output: a vector of strings, containing the tokens
*/
std::vector<std::string> tokenize(const std::string& str, char delimiter);

