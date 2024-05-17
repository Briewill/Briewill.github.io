/**
 *AbstactCommand.h
 * CSE 332S
 * Lab Num: 5
 * Purpose: Declarations for teh base class of lab 5. Function definitions can be found in the
 * respective source files for various commands (the subtypes of AbstractCommand).
*/

#pragma once

#include <string>

enum errors { //for cat command, and others
    INVALID_COMMAND = 1,
    FILE_DOES_NOT_EXIST,
    APPEND_ERROR,
    WRITE_ERROR,
    FILE_OPEN_ERROR,
    COPY_FAILURE
};

class AbstractCommand{
public:
    virtual int execute(std::string) = 0;   //parameter holds any information passed to command
    virtual void displayInfo() = 0;         //essentially a usage message for the command
    virtual ~AbstractCommand() = default;
};