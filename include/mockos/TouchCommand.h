#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class TouchCommand : public AbstractCommand{
public:
    TouchCommand(AbstractFileSystem* fs, AbstractFileFactory* ff);
    ~TouchCommand() = default;

    void displayInfo() override;
    int execute(std::string filename) override;

private:
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;

};
enum TouchReturns {
    NOT_ADDED = 1,
    NOT_CREATED = 2,
    IMPROPER_THIRD_ARG = 3,
    FILENAME_ISSUE
};