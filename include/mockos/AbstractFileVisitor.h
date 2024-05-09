#pragma once
#include "AbstractFile.h"
#include <vector>
#include <string>
#include "TextFile.h"
#include "ImageFile.h"

class AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile* tFile) = 0;
	virtual void visit_ImageFile(ImageFile* iFile) = 0;
};