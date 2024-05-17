/**
 * AggregateCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Purpose: This file contains definitions for CommandPrompt.h. It prompts uers for input and handles certain
 * undesirable cases.
*/
#include<iostream>
#include<sstream>
#include "../include/mockos/CommandPrompt.h"
#include "../include/mockos/TouchCommand.h"


CommandPrompt::CommandPrompt() : fileSystem(nullptr), fileFactory(nullptr) {

}

void CommandPrompt::setFileSystem(AbstractFileSystem* fs){  //sets the AbstractFileSystem pointer member var = parameter passed to this method
    fileSystem = fs;
}

void CommandPrompt::setFileFactory(AbstractFileFactory *ff) {
    fileFactory = ff;
}

int CommandPrompt::addCommand(std::string commandName, AbstractCommand *command) {
    auto insertionCheck = commands.insert({commandName,command});   //pair::first set to iterator pointing to new insertion
    if(insertionCheck.second){
        return SUCCESS;
    }else
        return INSERT_FAIL;
}

int CommandPrompt::listCommands() {
    //for each pair (element in map)
    for(const auto& pair : commands){
        std::cout<<pair.first<<std::endl;
    }
    return SUCCESS;
}

std::string CommandPrompt::prompt() {
    std::string userInput;
    std:: string message = "Enter a command, q to quit, help for a list of commands, or \n"
                           "help followed by a command name for more information about \n"
                           "that command. \n"
                           "$  ";
    std::cout<<message;
    std::getline(std:: cin, userInput);
    return userInput;
}

int CommandPrompt::run() {
    std::string userInput;
    while(true) {
        userInput = prompt();
        if (userInput == "q") {
            std::cout << "user quit" << std::endl;
            return QUIT;
        } else if (userInput == "help") {
            listCommands();
        }
        else {
            size_t found = userInput.find(' ');
            if (found != std::string::npos){    // space found input contains more than one word
               std::istringstream iss(userInput);
               std::string firstWord;
               std::string secondWord;
               iss>>firstWord;  //extract first word
               std::getline(iss >> std::ws, secondWord);
               if (firstWord == "help"){
                   bool foundH = false;
                   for(const auto& pair : commands){
                       if(pair.first == secondWord){
                           pair.second->displayInfo(); //implement this
                           foundH = true;
                       }
                    }
                   !foundH && std::cout << "command does not exist" << std::endl;
               }
               else{
                   bool found = false;
                   for(const auto& pair : commands) {
                       if (pair.first == firstWord) {
                           found = true;
                           int result = pair.second->execute(secondWord);
                           if (result != SUCCESS) {
                               // Command execution failed
                               std::cout << "Command failed." << std::endl;
                           }
                       }
                   }
                   if (!found) {
                       std::cout << "Command not found." << std::endl;
                   }
               }

            }else{  //no space found input is just one word
                bool found = false;
                for (const auto& pair : commands){  //search for command that matches input
                    if(pair.first == userInput){    //command found
                        int result = pair.second->execute("");
                        if(result != SUCCESS){    //execution failed
                           std::cout<<"Command failed."<<std::endl;

                        }
                        else {
                            found = true;
                        }
                    }
                }
                if (!found) {
                    std::cout << "Command not found." << std::endl;
                }
            }

        }
    }
}