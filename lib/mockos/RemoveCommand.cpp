/**
 * RemoveCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Owen
 * Purpose: This file contains definitions for RemoveCommand.h. It deletes a file from the filesystem upon user input.
*/

#include <iostream>
//#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/RemoveCommand.h"
#include "mockos/SimpleFileSystem.h"


RemoveCommand::RemoveCommand(AbstractFileSystem* fs) {
    fileSystem = fs;
}

void RemoveCommand::displayInfo() {
    std::cout << "remove removes a file from the system, remove can be invoked with command: remove <filename>" << std::endl;
}

int RemoveCommand::execute(std::string filename) {
    if (filename == "") { //if no filename is provided
        std::cout << "Must provide a filename to remove" << std::endl;
        return NEED_FILE;
    }
    else
    { //if a filename is provided, then the file is deleted form the system and a print statement is made to say whether or not it was deleted
        int ret = fileSystem->deleteFile(filename);
        if (ret == SUCCESS) {
            std::cout << "File deleted" << std::endl;
        }
        else {
            std::cout << "File unable to be deleted" << std::endl;
        }
        return ret;
    }
}