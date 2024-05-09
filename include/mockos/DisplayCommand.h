/**
 *DisplayCommand.h
 * CSE 332S
 * Lab Num: 5
* Author: Megan
* Purpose: Declarations for DisplayCommand.h. Definitions can be found in DisplayCommand.cpp.
*/

#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
//#include "AbstractFileFactory.h"

#include "../include/mockos/BasicDisplayVisitor.h"

class DisplayCommand : public AbstractCommand {
public:
    DisplayCommand(AbstractFileSystem* fs);
    ~DisplayCommand();

    void displayInfo() override;
    int execute(std::string secondString) override;

private:
    AbstractFileSystem* fileSystem;
    //AbstractFileFactory* fileFactory;
    BasicDisplayVisitor* visitor;
};