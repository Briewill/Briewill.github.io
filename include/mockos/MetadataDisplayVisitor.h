#pragma once
#include "../include/mockos/AbstractFileVisitor.h"
class AbstractFile;

class MetadataDisplayVisitor : public AbstractFileVisitor{
public:
	virtual void visit_TextFile(TextFile* tFile) override;
	virtual void visit_ImageFile(ImageFile* iFile) override;
};