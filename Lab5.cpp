#include "../include/mockos/CommandPrompt.h"
#include "../include/mockos/TouchCommand.h"
#include "../include/mockos/LSCommand.h"
#include "../include/mockos/RemoveCommand.h"
#include "../include/mockos/CatCommand.h"
#include "../include/mockos/DisplayCommand.h"
#include "../include/mockos/CopyCommand.h"
#include "../include/mockos/RenameParsingStrategy.h"
#include "../include/mockos/AbstractParsingStrategy.h"
#include "../include/mockos/MacroCommand.h"
#include "mockos/EditDisplayParsingStrategy.h"
#include "../include/mockos/AggregateCommand.h"

#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"


int main() {
    SimpleFileSystem fileSystem = SimpleFileSystem();
    SimpleFileFactory fileFactory = SimpleFileFactory();
    TouchCommand touchCommand = TouchCommand(&fileSystem, &fileFactory);
    LSCommand lsCommand = LSCommand(&fileSystem);
    RemoveCommand removeCommand = RemoveCommand(&fileSystem);
    CatCommand catCommand = CatCommand(&fileSystem);
    DisplayCommand displayCommand = DisplayCommand(&fileSystem);
    CopyCommand copyCommand = CopyCommand(&fileSystem);
    AggregateCommand aggregateCommand = AggregateCommand(&fileSystem);

    RenameParsingStrategy renameParsingStrategy = RenameParsingStrategy();
    MacroCommand renameCommand =  MacroCommand(&fileSystem);
    renameCommand.setParseStrategy(&renameParsingStrategy);
    renameCommand.addCommand(&copyCommand);
    renameCommand.addCommand(&removeCommand);

    EditDisplayParsingStrategy editDisplayParsingStrategy = EditDisplayParsingStrategy();
    MacroCommand editDisplayCommand = MacroCommand(&fileSystem);
    editDisplayCommand.setParseStrategy(&editDisplayParsingStrategy);
    editDisplayCommand.addCommand(&catCommand);
    editDisplayCommand.addCommand(&displayCommand);


    CommandPrompt commandPrompt;


    commandPrompt.setFileSystem(&fileSystem);
    commandPrompt.setFileFactory(&fileFactory);
    commandPrompt.addCommand("touch", &touchCommand);
    commandPrompt.addCommand("ls", &lsCommand);
    commandPrompt.addCommand("rm", &removeCommand);
    commandPrompt.addCommand("cat", &catCommand);
    commandPrompt.addCommand("ds", &displayCommand);
    commandPrompt.addCommand("cp", &copyCommand);
    commandPrompt.addCommand("rn", &renameCommand);
    commandPrompt.addCommand("ed", &editDisplayCommand);
    commandPrompt.addCommand("agg", &aggregateCommand);

    commandPrompt.run();


    return 0;
}