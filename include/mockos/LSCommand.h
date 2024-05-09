/**
 *LSCommand.h
 * CSE 332S
* Lab Num: 5
* Author: Owen
* Purpose: Declarations for LSCommand.h. Definitions can be found in LSCommand.cpp.
*/

#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
//#include "AbstractFileFactory.h"

class LSCommand : public AbstractCommand {
public:
    LSCommand(AbstractFileSystem* fs);
    ~LSCommand() = default;

    void displayInfo() override;
    int execute(std::string secondArg) override;

private:
    AbstractFileSystem* fileSystem;
    //AbstractFileFactory* fileFactory;

};
enum LSRET {
    NUM_PER_LN = 2
};