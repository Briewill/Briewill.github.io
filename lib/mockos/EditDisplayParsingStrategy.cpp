/**
 * EditDisplayParsingStrategy.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Brienne Williams
 * Purpose: This file contains definitions for EditDisplayParsingStrategy.h. It parses user input to be applicable
 * for macrocommand.cpp.
*/

#include "../include/mockos/EditDisplayParsingStrategy.h"
#include <sstream>
#include <iostream>

std::vector<std::string> EditDisplayParsingStrategy::parse(std::string input) {

    std::vector<std::string> parsedInput;
    std::istringstream iss(input);
    std:: string token;
    std:: string tokenTwo;
    while (iss >> token){           //existing file and new file name
        parsedInput.push_back(token); //parsed input [0] will have file name no -a
        while (iss>>tokenTwo) {
            std:: string parsedAtZero = token + " " + tokenTwo;
            parsedInput[EXISTING_FILE].clear();
            parsedInput[EXISTING_FILE] = parsedAtZero;
            parsedInput.push_back(token); // makes paredInput[1] the  existingfilename;
        }
    }

    return parsedInput;
}