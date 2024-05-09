/**
 * LSCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Owen
 * Purpose: This file contains definitions for LSCommand.h. Lists the files available to users.
*/

#include <iostream>
#include "../include/mockos/LSCommand.h"
#include "mockos/SimpleFileSystem.h"
#include "../include/mockos/MetadataDisplayVisitor.h"


LSCommand::LSCommand(AbstractFileSystem* fs) {
    fileSystem = fs;
}

void LSCommand::displayInfo() {
    std::cout << "ls gives the list of files in the system, ls can be invoked with command: ls, or with the command ls -m" << std::endl;
}

int LSCommand::execute(std::string secondArg) {
    std::map<std::string, AbstractFile*> map = fileSystem->getMap(); //map of all files
    std::set<std::string> files = fileSystem->getFileNames(); //map of file names

    MetadataDisplayVisitor metaVisitor = MetadataDisplayVisitor(); //visitor

    if (secondArg == "") { //if not -m
        int count = 0;
        for (auto file : files) {
            if (count % NUM_PER_LN == 0) {
                std::cout << file << "    ";
            }
            else {
                std::cout << file << std::endl;
            }
            count++;
        }
        if (count % NUM_PER_LN != 0) {
            std::cout << std::endl;
        }
    }
    else if (secondArg == "-m") { //for -m
        for (auto pair : map) {
            pair.second->accept(&metaVisitor);
        }
    }
    else { //if the input is bad
        std::cout << "Invalid ls input" << std::endl;
    }
    return SUCCESS;
}