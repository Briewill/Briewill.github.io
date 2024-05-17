#pragma once
#include "../include/mockos/AbstractFileVisitor.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
	virtual void visit_TextFile(TextFile* tFile);
	virtual void visit_ImageFile(ImageFile* iFile);
private:
};