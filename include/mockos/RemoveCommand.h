/**
 *RemoveCommand.h
 * CSE 332S
 * Lab Num: 5
 * Author: Owen
 * Purpose: Declarations for RemoveCommand.h; publicly inherent the AbstractCommand interface.
 * Definitions can be found in MacroComand.cpp.
*/

#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
//#include "AbstractFileFactory.h"

class RemoveCommand : public AbstractCommand {
public:
    RemoveCommand(AbstractFileSystem* fs);
    ~RemoveCommand() = default;

    void displayInfo() override;
    int execute(std::string filename) override;

private:
    AbstractFileSystem* fileSystem;
    //AbstractFileFactory* fileFactory;

};
enum RMRets {
    NEED_FILE = 1
};