#include <iostream>
#include "../include/mockos/MetadataDisplayVisitor.h"
#include "../include/mockos/AbstractFile.h"



void MetadataDisplayVisitor::visit_TextFile(TextFile* file) {
	std::string name = file->getName();
	std::cout << name << " " << "text" << " " << file->getSize() << std::endl; //note: we have to use this format to pass the unit tests
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
	std::string name = file->getName();
	std::cout << name << " " << "image" << " " << file->getSize() << std::endl;
}