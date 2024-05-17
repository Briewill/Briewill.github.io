#include <iostream>
#include<sstream>
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/TouchCommand.h"
#include "../include/mockos/PasswordProxy.h"
#include "mockos/SimpleFileSystem.h"


TouchCommand::TouchCommand(AbstractFileSystem *fs, AbstractFileFactory *ff) {
    fileSystem = fs;
    fileFactory = ff;
}

void TouchCommand::displayInfo() {
    std::cout<<"touch creates a file, touch can be invoked with command: touch <filename>"<<std::endl;
}

int TouchCommand::execute(std::string filename) {
    if (filename == "") {
        std::cout << "Filename needed for creation" << std::endl; //no name provided
        return FILENAME_ISSUE;
    }
    else { //there was a name provided
        size_t found = filename.find(' ');
        if (found != std::string::npos) {  //if it is password protected
            std::istringstream iss(filename);
            std::string firstWord;
            std::string secondWord;
            iss >> firstWord >> secondWord;
            if (secondWord != "-p") { //improper third argument
                std::cout << "Improper third argument" << std::endl;
                return IMPROPER_THIRD_ARG;
            }
            else { // used -p
                AbstractFile* result = fileFactory->createFile(firstWord);
                std::string pass;
                std::cout << "What is the password?" << std::endl; //gets the password for the file
                std::getline(std::cin, pass);
                if (result != nullptr) {
                    AbstractFile* prox = new PasswordProxy(result, pass);
                    if (fileSystem->addFile(firstWord, prox) != SUCCESS) { //could not be added
                        delete result;
                        std::cout << "file could not be added" << std::endl;
                        return NOT_ADDED;
                    }
                    else { //file added
                        std::cout << "file added" << std::endl;
                        return SUCCESS;
                    }
                }
                else { //file not created
                    std::cout << "file could not be created" << std::endl;
                    return NOT_CREATED;
                }
            }
        }
        else { //not protected
            AbstractFile* result = fileFactory->createFile(filename);
            if (result != nullptr) {
                if (fileSystem->addFile(filename, result) != SUCCESS) { //not added
                    delete result;
                    std::cout << "file could not be added" << std::endl;
                    return NOT_ADDED;
                }
                else { //added
                    std::cout << "file added" << std::endl;
                    return SUCCESS;
                }
            }
            else { //not created
                std::cout << "file could not be created" << std::endl;
                return NOT_CREATED;
            }
        }
    }
}