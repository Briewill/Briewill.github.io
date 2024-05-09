/**
 *EditDisplayParsingStrategy.h
 * CSE 332S
* Lab Num: 5
* Author: Brienne
* Purpose: Declarations for EditDisplayParsingStrategy.h. Definitions can be found in EditDisplayParsingStrategy.cpp.
 * Publicly inherits from teh abstract command interface.
*/

#pragma once
#include "AbstractParsingStrategy.h"
#include <vector>
# include <string>


class EditDisplayParsingStrategy : public AbstractParsingStrategy{
public:
    ~EditDisplayParsingStrategy() = default;
    std::vector<std::string> parse(std::string input) override;

};

enum ArrayIndicies {
    EXISTING_FILE = 0,
};