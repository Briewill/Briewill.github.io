# Lab 5

Brienne: Handled the implementation of macroCommands: rn and ed; lab questions 7-onward; enums for macrocommands;
testing and documentation: file header and readMe tests.

Megan: Handled implementation of cat, ds, cp; Adjustments to lab5.cpp; lab questions 4-6; switching 
getType to metaDisplay; Extra Credit.

Owen: Handled implementation for  ls, rm, and touch commands; lab question 1-3; lots of debugging especially unit tests;
enums for all files excluding macrocommands.

ERRORS: 
- No exceptions were thrown that could not be fixed with quick syntax adjustments.
- Unit Test failed for RenameParsingStrategy:
  - Expected length was 2 but actual length was 3
    - Issue: input was being read in via iss too frequently, and MacroCommand.cpp was handling some sting manipulation
    after parsing.
    - Correction: Improved logic and concatenated iss's before adding them to paredInput vector. This also allowed
    for a more dynamic and concise implementation in MacroCommand.cpp

TESTS:
Giving a command that doesn't exist results in an error message informing the user that the command does not exist.
Calling touch without a filename results in an error message saying a filename must be provided.
Calling cat without a file results in an invalid command message being printed.
Entering :q after a cat command results in none of the input being saved. Entering a :wq results in the input being saved.
Calling ds on a file that does not exist results in a message informing the user that such a file does not exist.
Calling cp without two files results in an invalid command message.
Calling cp with only one file and no name results in a message instructing the user to provide a preexisting file and a file name without extensions.
Calling cp with two valid parameters results in a copy of the file being made.
ls displays all the files in the system.
Attemping to append to an image file will result in an error message.

EC Documentation:

Design Pattern: Visitor

Implemented aggregate statistics via custom command "agg." Created AggregateVisitor and AggregateCommand classes which display the following information:
Total number of files
Number of image files
Number of text files
Total space taken by files (bytes)
Space taken by image files
Space taken by text files
Largest image file
Largest text file

Ec Tests: Created text and image files via touch and cat, then displayed them to make sure information was being displayed properly.
ERROR: Every time agg was called, it would add the sums, resulting in abnormally large numbers not reflective of the state of the system.
RESOLVED: Added refresh() method that would reset member variable counts after each run of agg.
RETESTING: called agg several times on an unchanging system, everything is normal.

ERROR: nullptr exception thrown when trying to display systems with only image or only text files.
RESOLVED: added set of conditions that changed printed messages depending on whether none, one, or both file types are present.
RETESTING: created a file system with only text files and called agg, text files are displayed normally and image files show N/A



GENERAL TESTING:
- TOUCH COMMANDS FOR TEXT AND IMAGE FILES & LIST COMMAND:

  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  touch file.txt
  file added
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  touch file.img
  file added
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  ls
  file.img    file.txt
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $


- REMOVE COMMAND:
  $  ls
  file.img    file.txt
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  rm file.img
  File deleted
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  ls
  file.txt    
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $

- CAT COMMAND FOR IMAGE AND TEXT FILES AND DISPLAY COMMAND:

$  cat file.txt
Please add input to replace the current file, then :wq to save and quit or :q to quit without saving.
This is contents for file.txt
:wq
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  ds file.txt
This is contents for file.txt 

$  cat image.img
Please add input to replace the current file, then :wq to save and quit or :q to quit without saving.
X X X X X3
:wq
3
Size: ; X X X X X
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  ds image.img
X X
 X
X X

- CAT WITH APPEND FOR TEXT AND IMAGE FILES:
  $  cat file.txt -a
  foo Please add data to be appended, then :wq to save and quit or :q to quit without saving.
  This is contents for file.txt
  THE INFOMRATION IN ALL CAPS HAS BEEN APPENDED TO FILE.TXT
  :wq
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  ds file.txt
  This is contents for file.txt THE INFOMRATION IN ALL CAPS HAS BEEN APPENDED TO FILE.TXT

Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  cat image.img -a
foo Please add data to be appended, then :wq to save and quit or :q to quit without saving.
X X X X X
X X X X X3
:wq
Not allowed to append to images.
append error 1
Command failed.
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  
    - Note: Cat odes not allow a user to append to image files as expeted

- COPY COMMAND TEXT FILES:
  $  touch tobecopied.txt
  file added
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  
  $  cat tobecopied.txt
  Please add input to replace the current file, then :wq to save and quit or :q to quit without saving.
  Lets see if this input cpoies to the new file.
  :wq
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  cp tobecopied.txt newcopiedfile
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  ds newcopiedfile.txt
  Lets see if this input cpoies to the new file.
  - Note: Contents of file copies over sucesffully.

- COPY COMMAND IMAGE FILES
  $  ls
  imagetocopy.img    
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  ds imagetocopy.img
  X X
   X
  X X
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  cp imagetocopy.img newImageFile
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  ds newImageFile.img
  X X
   X
  X X

- RENAME MACROCOMMAND FOR TEXT: 
  $  touch oldfile.txt
  file added
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  ls
  oldfile.txt    
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  rn oldfile.txt NewName
  File deleted
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  ls
  NewName.txt    
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command. 


- RENAME MACROCOMMAND FOR IMAGE: 

$  touch oldfile.img
file added
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  ls
oldfile.img    
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  rn oldfile.img NewFile
File deleted
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  ls
NewFile.img    
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command. 

- EDIT AND DISPLAY MACRO COMMAND FOR TEXT FILES WITHOUT APPEND:
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  touch textFile.txt
  file added
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  ed textFile.txt
  Please add input to replace the current file, then :wq to save and quit or :q to quit without saving.
  Lets see if this text displays right away?
  :wq
  Lets see if this text displays right away?
    -Note: Text displays right away as excepted

- EDIT AND DISPLAY MACRO COMMAND FOR TEXT FILES WITH APPEND:

$  touch existingfile.txt
file added
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  cat existingfile.txt
Please add input to replace the current file, then :wq to save and quit or :q to quit without saving.
Contexts for file
:wq
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$  ed existingfile.txt -a
foo Please add data to be appended, then :wq to save and quit or :q to quit without saving.
Contexts for file
LETS SEE IF THIS APPENED CONTEXT DISPLAYS RIGHT AWAY
:wq
Contexts for fileLETS SEE IF THIS APPENED CONTEXT DISPLAYS RIGHT AWAY

- EDIT AND DISPLAY MACRO COMMAND FOR IMAGE FILES WITHOUT APPEND:
  $  ls
  imagefile.img    
  Enter a command, q to quit, help for a list of commands, or
  help followed by a command name for more information about
  that command.
  $  ed imagefile.img
  Please add input to replace the current file, then :wq to save and quit or :q to quit without saving.
  X X X X X3
  :wq
  3
  Size: ; X X X X X
  X X
  X
  X X
  - Notes: Image was edited and displayed right away as expected

- EDIT AND DISPLAY MACRO COMMAND FOR IMAGE FILES With APPEND:
  $  ed imagefile.img -a
  foo Please add data to be appended, then :wq to save and quit or :q to quit without saving.
  X X X X X
  X X X X X3
  :wq
  Not allowed to append to images.
  - Note: Program printed not allowed to append to images as expected 
