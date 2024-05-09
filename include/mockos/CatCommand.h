/**
 *CatCommand.h
 * CSE 332S
 * Lab Num: 5
* Author: Megan
* Purpose: Declarations for CatCommand.h. Definitions can be found in CatCommand.cpp.
*/

#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "../include/mockos/MetadataDisplayVisitor.h"

class CatCommand : public AbstractCommand {
public:
    CatCommand(AbstractFileSystem* fs);
    ~CatCommand() = default;

    void displayInfo() override;
    int execute(std::string secondString) override;

private:
    AbstractFileSystem* fileSystem;
};