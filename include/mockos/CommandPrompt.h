/**
 *CommandPrompt.h
 * CSE 332S
 * Lab Num: 5
* Purpose: Declarations for CommandPrompt.h. Definitions can be found in ComandPrompt.cpp.
*/

#pragma once

#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class CommandPrompt{
private:
    std::map<std::string, AbstractCommand* >(commands);
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;
public:
    CommandPrompt();
    virtual ~CommandPrompt() = default;
    void setFileSystem(AbstractFileSystem* fs);    //sets the AbstractFileSystem pointer member var = parameter passed to this method
    void setFileFactory(AbstractFileFactory* ff);  //sets the AbstractFileFactory pointer
    int addCommand(std::string commandName, AbstractCommand* command); //inserts parameter passed as a pair into the map of commands
    int run();
protected:
    int listCommands();      //iterates over each command in the map and prints the name
    std::string prompt();   //prompts the user for input

};
enum ComPrEn {
    INSERT_FAIL = 1,
    QUIT = 2
};