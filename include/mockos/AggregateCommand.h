/**
 *MacrCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Megan
 * Purpose: Declarations for AggregateCommand.h; publicly inherent the AbstractCommand interface.
 * Definitions can be found in AggregateCommand.cpp.
*/

#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "../include/mockos/AggregateVisitor.h"

class AggregateCommand : public AbstractCommand {
public:
    AggregateCommand(AbstractFileSystem* fs);
    ~AggregateCommand();

    void displayInfo() override;
    int execute(std::string secondString) override;

private:
    AbstractFileSystem* fileSystem;
    AggregateVisitor* aggVisitor;
};