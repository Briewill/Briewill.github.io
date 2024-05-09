/**
 * RenameParsingStrategy.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Megan
 * Purpose: This file contains definitions for CatCommand.h. It implemetns teh "cat" command which allows users
 * to edit and append edits their files.
*/

#include <iostream>
#include <sstream>
#include "../include/mockos/CatCommand.h"
#include "mockos/SimpleFileSystem.h"

//constructor
CatCommand::CatCommand(AbstractFileSystem* fs) {
    fileSystem = fs;
}


void CatCommand::displayInfo() {
    std::cout << "The cat command allows you to write to files. Call cat <filename> to replace the contents of your file. Call cat <filename> -a to append content to the end of the file. You cannot append to image files." << std::endl;
}

int CatCommand::execute(std::string secondString) {
    std::map<std::string, AbstractFile*> map = fileSystem->getMap();
    std::set<std::string> files = fileSystem->getFileNames();

    if (secondString == "") { //if no arguments, CatCommand just returns
        std::cout << "Invalid command." << std::endl;
        return errors::INVALID_COMMAND; //1, enum defined in AbstractCommand
    }

    size_t found = secondString.find(' ');

    if (found != std::string::npos) { // cat <filename> -a
        std::istringstream iss(secondString);

        std::string firstWord; // <filename>
        std::string secondWord; // -a

        iss >> firstWord;  //extract first word
        iss >> secondWord; //extract second

        if (secondWord != "-a") { // not an -a
            std::cout << "Invalid command." << std::endl;
            return errors::INVALID_COMMAND;
        }

        auto iterator = map.find(firstWord);
        if (iterator == map.end()) { //no such file in the map
            std::cout << "No such file exists." << std::endl;
            return errors::FILE_DOES_NOT_EXIST;
        }

        //if we've gotten to this point, we have a valid cat <filename> -a command

        bool exit = false;
        std::string input;
        std::vector<char> tempSave;

        std::cout << "foo Please add data to be appended, then :wq to save and quit or :q to quit without saving." << std::endl;

        AbstractFile* file = fileSystem->openFile(firstWord);

        std::vector<char> contents = file->read();
        for (char character : contents) {
            std::cout << character;
        }

        std::cout << std::endl;


        while (!exit) {
            std::getline(std::cin, input);
            if (input == ":wq") {
                if ((!tempSave.empty()) && (tempSave.back() == '\n')) {
                    tempSave.pop_back();
                }
                if (file == nullptr) {
                    return errors::WRITE_ERROR;
                }
                int result = file->append(tempSave);

                exit = true;
                fileSystem->closeFile(file);
                if (result != SUCCESS) {

                    std::cout << "append error " << result << std::endl;

                    return errors::APPEND_ERROR;
                }
            }
            else if (input == ":q") {
                exit = true;
                fileSystem->closeFile(file);
            }
            else {
                input = input + "\n";
                for (char character : input) {
                    tempSave.push_back(character);
                }
            }
        }

        return SUCCESS;
    }
    else { //cat <filename>
        std::istringstream iss(secondString);

        std::string firstWord; // <filename>
        iss >> firstWord;

        auto iterator = map.find(firstWord);
        if (iterator == map.end()) { //no such file in the map
            std::cout << "No such file exists." << std::endl;
            return errors::FILE_DOES_NOT_EXIST;
        }

        bool exit = false;
        std::string input;
        std::vector<char> tempSave;

        std::cout << "Please add input to replace the current file, then :wq to save and quit or :q to quit without saving." << std::endl;

        AbstractFile* file = fileSystem->openFile(firstWord);

        while (!exit) {
            std::getline(std::cin, input);
            if (input == ":wq") {
                if ((!tempSave.empty()) && (tempSave.back() == '\n')) {
                    tempSave.pop_back();
                }
                if (file == nullptr) {
                    return errors::WRITE_ERROR;
                }
                int result = file->write(tempSave);
                exit = true;
                fileSystem->closeFile(file);
                if (result != 0) {
                    std::cout << "append error " << result << std::endl;
                    return errors::WRITE_ERROR;
                }
            }
            else if (input == ":q") {
                exit = true;
                fileSystem->closeFile(file);
            }
            else {
                input = input + "\n";
                for (char character : input) {
                    tempSave.push_back(character);
                }
            }
        }

        return SUCCESS;
    }
    return SUCCESS;
}