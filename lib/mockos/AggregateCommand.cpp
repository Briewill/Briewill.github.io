/**
 * AggregateCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Purpose: This file contains definitions for AggeragateCommand.h.
*/

#include <iostream>
#include <sstream>
#include "../include/mockos/AggregateCommand.h"
#include "mockos/SimpleFileSystem.h"

//constructor
AggregateCommand::AggregateCommand(AbstractFileSystem* fs) {
    fileSystem = fs;
    aggVisitor = new AggregateVisitor();
}

AggregateCommand::~AggregateCommand() {
    delete aggVisitor;
}

//display info
void AggregateCommand::displayInfo() {
    std::cout << "The agg command prints out aggregated statistics about the file system. Calling agg will display all aggregated statistics. Calling agg -c will display count statistics. Calling agg -s will display size statistics." << std::endl;
}

int AggregateCommand::execute(std::string secondString) {
    std::map<std::string, AbstractFile*> map = fileSystem->getMap();
    std::set<std::string> files = fileSystem->getFileNames();

    if (map.empty()) {
        std::cout << "No files to display." << std::endl;
        return SUCCESS;
    }

    for (auto pair : map) {  //go through every file
        AbstractFile* curFile = pair.second;
        curFile->accept(aggVisitor);
    }

    if (secondString == "") { //if no arguments, print all statistics
        aggVisitor->print_all();
    }
    else if (secondString == "-c") {
        //print count statistics
        aggVisitor->print_counts();
    }
    else if (secondString == "-s") {
        //print size statistics
        aggVisitor->print_sizes();
    }
    else { //invalid input
        std::cout << "Invalid command." << std::endl;
        aggVisitor->reset();
        return errors::INVALID_COMMAND;
    }
    aggVisitor->reset();
    return SUCCESS;
}