/**
 * DisplayCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Megan
 * Purpose: This file contains definitions for DisplayCommand.h. It allows users to see the contens of their file.
*/

#include <iostream>
#include <sstream>
#include "../include/mockos/DisplayCommand.h"
#include "mockos/SimpleFileSystem.h"

//constructor
DisplayCommand::DisplayCommand(AbstractFileSystem* fs) {
    fileSystem = fs;
    visitor = new BasicDisplayVisitor();
}

DisplayCommand::~DisplayCommand() {
    delete visitor;
}

//display info
void DisplayCommand::displayInfo() {
    std::cout << "Display displays the contents of a specified file. Call 'ds <filename> -d' to display the unformatted file data. Call 'ds <filename> to display the formatted file data." << std::endl;
}

int DisplayCommand::execute(std::string secondString) {
    std::map<std::string, AbstractFile*> map = fileSystem->getMap();
    std::set<std::string> files = fileSystem->getFileNames();

    if (secondString == "") { //if no arguments, DisplayCommand just returns
        std::cout << "Invalid command." << std::endl;
        return errors::INVALID_COMMAND; //1, enum defined in AbstractCommand
    }

    size_t found = secondString.find(' ');

    if (found != std::string::npos) { // ds <filename> -d
        std::istringstream iss(secondString);

        std::string firstWord; // <filename>
        std::string secondWord; // -d

        iss >> firstWord;  //extract first word
        iss >> secondWord; //extract second

        if (secondWord != "-d") {
            std::cout << "Invalid command." << std::endl;
            return errors::INVALID_COMMAND;
        }

        auto iterator = map.find(firstWord);
        if (iterator == map.end()) { //no such file in the map
            std::cout << "No such file exists." << std::endl;
            return errors::FILE_DOES_NOT_EXIST;
        }

        //valid ds command

        AbstractFile* file = fileSystem->openFile(firstWord);
        if (file == nullptr) {
            std::cout << "Failed to open file." << std::endl;
            return errors::FILE_OPEN_ERROR;
        }

        std::vector<char> contents = file->read();
        for (char character : contents) {
            std::cout << character;
        }

        std::cout << std::endl;

        fileSystem->closeFile(file);
    }
    else { //ds <filename>
        std::istringstream iss(secondString);

        std::string firstWord; // <filename>
        iss >> firstWord;

        auto iterator = map.find(firstWord);
        if (iterator == map.end()) { //no such file in the map
            std::cout << "No such file exists." << std::endl;
            return errors::FILE_DOES_NOT_EXIST;
        }

        AbstractFile* file = fileSystem->openFile(firstWord);
        if (file != nullptr) {
            file->accept(visitor);
        }
        else {
            std::cout << "file is nullptr" << std::endl;
        }

        fileSystem->closeFile(file);
    }
    return SUCCESS;
}