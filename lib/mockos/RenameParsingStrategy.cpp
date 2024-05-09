/**
 * RenameParsingStrategy.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Brienne Williams
 * Purpose: This file contains definitions for RenameParsingStrategy.h. It parses user input to be applicable
 * for macrocommand.cpp.
*/

#include "../include/mockos/RenameParsingStrategy.h"
#include <sstream>

std::vector<std::string> RenameParsingStrategy::parse(std::string input) {

    std::vector<std::string> parsedInput;
    std::istringstream iss(input);
    std:: string token;
    std:: string tokenTwo;

    while (iss >> token){           //existing file and new file name
    while (iss>>tokenTwo){
        std::string parseAtZero = token + " " + tokenTwo;
        parsedInput.push_back(parseAtZero);
        parsedInput.push_back(token);
    }



    }
    return parsedInput;
}