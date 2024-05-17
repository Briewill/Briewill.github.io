/**
 *CopyCommand.h
 * CSE 332S
 * Lab Num: 5
* Author: Megan
* Purpose: Declarations for CopyCommand.h. Definitions can be found in CopyCommand.cpp.
*/

#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
//#include "AbstractFileFactory.h"

//#include "../include/mockos/BasicDisplayVisitor.h"
//#include "../include/mockos/MetadataDisplayVisitor.h"

class CopyCommand : public AbstractCommand {
public:
    CopyCommand(AbstractFileSystem* fs);
    ~CopyCommand() = default;

    void displayInfo() override;
    int execute(std::string secondString) override;

private:
    AbstractFileSystem* fileSystem;
    //AbstractFileFactory* fileFactory;
    //BasicDisplayVisitor* visitor;
};