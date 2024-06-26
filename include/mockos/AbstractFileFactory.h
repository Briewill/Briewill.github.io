#pragma once
#include "AbstractFile.h"

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(std::string name) = 0;
};

