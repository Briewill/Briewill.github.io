#pragma once
#include "AbstractFileFactory.h"
#include "AbstractFile.h"
#include "SimpleFileSystem.h"

class SimpleFileFactory : public AbstractFileFactory {
public:
	AbstractFile* createFile(std::string name);
};


enum SFFF {
	FILE_TYPE = 3
};