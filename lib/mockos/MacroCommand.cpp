/**
 * RenameParsingStrategy.cpp
 * CSE 332S
 * Lab Num: 5
 * Author: Brienne
 * Purpose: This file contains definitions for MacroCommand.h. It utilizes parsed input from parsing strategies
 * from respective macro commands to execute multiple simpler commands in a single propmt.
 * to edit and append edits their files.
*/

#include <iostream>
#include "../include/mockos/MacroCommand.h"
#include "../include/mockos/AbstractParsingStrategy.h"


MacroCommand::MacroCommand(AbstractFileSystem* fs) : parsingStrategy(nullptr){
    fileSystem = fs;

}


void MacroCommand::addCommand(AbstractCommand* command) {
    macroCommands.push_back(command);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy *strategy) {
    parsingStrategy = strategy;
}

int MacroCommand::execute(std::string input ) {
    if(!parsingStrategy){       //parsing strategy is not set
        return NO_SET_PARSINGSTRATEGY;
    }
    std::vector<std::string> parsedInput = parsingStrategy->parse(input);
    if (parsedInput.size() < 1){
        return NOT_ENOUGH_INPUT;         //not long enough
    }
    std::string existingFile = parsedInput[PARSED_INDEX_ZERO];
    std:: string removeCommand = parsedInput[PARSED_INDEX_ONE];
    int copyResult = 0;
    int catResult = 0;
    int displayResult = 0;

    if(parsedInput.size()<=MIN_VECTOR_SIZE) {
        catResult = macroCommands[CAT_COMMAND]->execute(existingFile);
        if (catResult != SUCCESS){
            return catResult;
        }
        displayResult = macroCommands[DISPLAY_COMMAND]->execute(existingFile);
        if(displayResult != SUCCESS) {
            return displayResult;
        }
    }else {
        copyResult = macroCommands[COPY_COMMAND]->execute(existingFile);


        if (copyResult != 0) {       //copy failed
            return copyResult;
        }
        //execute remove commands
        int removeResult = macroCommands[REMOVE_COMMAND]->execute(removeCommand);
        if (removeResult != SUCCESS) {
            //remove failed
            return removeResult;
        }
    }
        return 0; //copy and remove success

}

void MacroCommand::displayInfo() {
    if (!parsingStrategy) {
        std::cout << "Parsing strategy is not set." << std::endl;
        return;
    }

        std::cout<<"rn and ed are both macrocommands.\n rn command allows you to rename a file. Rename can be invoked and executed with "
                  "rn <existing_file> <new_name_with_no_extension>. \n ed allows you to append a file ann display your edits. Edit and display"
                  "be executed wtih ed <existing_file_name>."<<std::endl;



}

