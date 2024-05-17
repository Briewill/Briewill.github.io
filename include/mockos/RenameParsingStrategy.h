/**
 *RenameParsingStrategy.h
 * CSE 332S
 * Lab Num: 5
 * Author: Brienne Williams, Brienne.a.williams@wustl.edu
 * Purpose: Declarations for RenameParsingStrategy.cpp. Definitions can be found in RenameParsingStrategy.cpp.
 * Publicly inherits from AbstractParsingStrategy.
*/

#pragma once
#include "AbstractParsingStrategy.h"
#include <vector>
# include <string>


class RenameParsingStrategy : public AbstractParsingStrategy{
public:
    std::vector<std::string> parse(std::string input) override;
    ~RenameParsingStrategy() = default;
};