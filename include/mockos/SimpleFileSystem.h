#pragma once
#include <vector>
#include <string>
#include <set>
#include<map>
#include "AbstractFileSystem.h"
#include "AbstractFile.h"

class SimpleFileSystem : public AbstractFileSystem {
public:
	virtual int addFile(std::string s, AbstractFile* file);
	//virtual int createFile(std::string name);
	virtual int deleteFile(std::string name);
	virtual AbstractFile* openFile(std::string name);
	virtual int closeFile(AbstractFile* file);
	virtual std::set<std::string> getFileNames();
	virtual std::map<std::string, AbstractFile*> getMap();
	~SimpleFileSystem();
protected:
	std::map<std::string, AbstractFile*> files;
	std::set<AbstractFile*> openFiles;
};

enum SFSF {
	AR_IN_FILES = 1,
	NULLPTR_FILE = 2,
	NOT_A_TYPE = 3,
	AR_OPEN_FILES = 4,
	FILE_DNE = 5
};