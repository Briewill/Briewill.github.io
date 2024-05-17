#pragma once
#include "../include/mockos/AbstractFileVisitor.h"

class AggregateVisitor : public AbstractFileVisitor {
public:
	AggregateVisitor();
	virtual void visit_TextFile(TextFile* tFile);
	virtual void visit_ImageFile(ImageFile* iFile);
	void print_all();
	void print_counts();
	void print_sizes();
	void reset();
private:
	int numImg;
	int numText;
	int spaceImg;
	int spaceText;
	
	//for largest file
	AbstractFile* largestImg;
	AbstractFile* largestText;
	int curLargestImg;
	int curLargestText;
};