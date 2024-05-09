/**
 *MacrCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Brienne
 * Purpose: Declarations for MacroCommand.h; publicly inherent the AbstractCommand interface.
 * Definitions can be found in MacroComand.cpp.
*/

# pragma once

#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>
#include <string>

class MacroCommand : public AbstractCommand{
public:
    MacroCommand(AbstractFileSystem* fs);
    ~MacroCommand() = default;
    int execute(std::string input) override;
    void displayInfo() override;
    void addCommand(AbstractCommand*);
    void setParseStrategy(AbstractParsingStrategy*);


private:
    AbstractFileSystem* fileSystem;
    std::vector<AbstractCommand*> macroCommands;
     AbstractParsingStrategy* parsingStrategy;
};

enum renameMacroCommandIndicies{
    COPY_COMMAND = 0,
    REMOVE_COMMAND = 1
};

enum editDisplayMacroCommandIndicies{
    CAT_COMMAND = 0,
    DISPLAY_COMMAND = 1
};

enum parsedInputIndicies{
    PARSED_INDEX_ZERO = 0,
    PARSED_INDEX_ONE = 1
};

enum Erros{
    NO_SET_PARSINGSTRATEGY = -1,
    NOT_ENOUGH_INPUT = -2,
};

enum logic{

    MIN_VECTOR_SIZE = 1
};