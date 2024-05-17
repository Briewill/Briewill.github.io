/**
 * CopyCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Megan
 * Purpose: This file contains definitions for CopyComand.h. It allows users to copy the contents of an existing file
 * to a new file.
*/

#include <iostream>
#include <sstream>
#include "../include/mockos/CopyCommand.h"
#include "mockos/SimpleFileSystem.h"

//constructor
CopyCommand::CopyCommand(AbstractFileSystem* fs) {
    fileSystem = fs;
}

//display info
void CopyCommand::displayInfo() {
    std::cout << "Copy allows you to copy a preexisting file into a new file. Copy is called with 'cp <original_file_name> <copy_file_name>'. PLEASE NOTE: copy_file_name should not have an extension." << std::endl;
}

int CopyCommand::execute(std::string secondString) {
    std::map<std::string, AbstractFile*> map = fileSystem->getMap();
    std::set<std::string> files = fileSystem->getFileNames();

    if (secondString == "") { //if no arguments, return
        std::cout << "Invalid command." << std::endl;
        return errors::INVALID_COMMAND;
    }

    size_t found = secondString.find(' ');

    if (found != std::string::npos) {
        std::istringstream iss(secondString);

        std::string firstWord; // <filename>
        std::string secondWord; // <copyname>

        iss >> firstWord;  //extract first word
        iss >> secondWord; //extract second

        auto iterator = map.find(firstWord);
        if (iterator == map.end()) { //no such file in the map
            std::cout << "No such file exists." << std::endl;
            return errors::FILE_DOES_NOT_EXIST;
        }

        size_t foundExtension = secondWord.find('.');
        if (foundExtension != std::string::npos) {
            std::cout << "File copy name must not have extension." << std::endl;
            return errors::INVALID_COMMAND;
        }

        //valid copy command

        AbstractFile* file = fileSystem->openFile(firstWord);

        //look for the name
        size_t extensionPoint = firstWord.find('.');
        std::string name = firstWord.substr(extensionPoint);
        name = secondWord + name;

        //create a new file, "copy"
        AbstractFile* copy = file->clone(name);
        fileSystem->closeFile(file);
        if (copy == nullptr) {
            delete copy;
            std::cout << "Copy command failed due to nullptr" << std::endl;
            return errors::COPY_FAILURE;
        }
        int result = fileSystem->addFile(name, copy);
        if (result != SUCCESS) {
            delete copy;
            std::cout << "Copy command failed" << std::endl;
            return errors::COPY_FAILURE;
        }
        return SUCCESS;
    }
    else { //both names aren't provided
        std::cout << "Please provide a preexisting file and a new file name without extensions" << std::endl;
        return errors::INVALID_COMMAND;
    }
}