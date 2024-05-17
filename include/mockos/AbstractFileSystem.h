
#pragma once
#include "AbstractFile.h"
#include <vector>
#include <set>
#include <map>
#include <string>

class AbstractFileSystem {
public:
	virtual int addFile(std::string s, AbstractFile * file) = 0;
	//virtual int createFile(std::string name) = 0;
	virtual int deleteFile(std::string name) = 0;
	virtual AbstractFile* openFile(std::string name) = 0;
	virtual int closeFile(AbstractFile* file) = 0;
	virtual std::set<std::string> getFileNames() = 0;
	virtual std::map<std::string, AbstractFile*> getMap() = 0;
};