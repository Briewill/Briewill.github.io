#include <iostream>
#include <vector>
#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFileVisitor.h"

TextFile::TextFile(std::string string) : name(string) {

};

unsigned int TextFile::getSize() {
	return contents.size();
}

std::string TextFile::getName() {
	return name;
}

int TextFile::write(std::vector<char> vector) {
	contents = vector;
	return SUCCESS;
}

int TextFile::append(std::vector<char> vector) {
	for (int i = 0; i < vector.size(); ++i) {
		contents.push_back(vector[i]);
	}
	return SUCCESS;
}

std::vector<char> TextFile::read() {
	return contents;
}
void TextFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_TextFile(this);
}

AbstractFile* TextFile::clone(std::string newName) {
	TextFile* cloneF = new TextFile(*this);
	cloneF->name = newName;
	return cloneF;
}