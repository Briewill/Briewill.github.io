
#pragma once

#include <iostream>
#include <vector>
#include "../include/mockos/ImageFile.h"
#include "../include/mockos/AbstractFileVisitor.h"

ImageFile::ImageFile(std::string string) : name(string), size(0) {

};

unsigned int ImageFile::getSize() {
	return contents.size();
}

std::string ImageFile::getName() {
	return name;
}

char ImageFile::getCharSize() {
	return size;
}

int ImageFile::append(std::vector<char> vector) {
	std::cout << "Not allowed to append to images." << std::endl;
	return NOT_ALLOWED;
}

std::vector<char> ImageFile::read() {
	return contents;
}

int ImageFile::write(std::vector<char> vector) {
	if (vector.empty()) {
		std::cout << "Empty input vector." << std::endl;
		return INVALID_SIZE;
	}
	
	std::cout << vector[vector.size() - VECT_BORDER] << std::endl;

    if (vector.size()== EMPTY){
        size = EMPTY;
        contents = vector;
        return SUCCESS;
    }

	char s = vector[vector.size() - VECT_BORDER];
	size = s - '0';
	contents.clear();

	for (int i = 0; i < vector.size() - VECT_BORDER; ++i) {
		if (vector[i] != 'X' && vector[i] != ' ') {
			std::cout << "not a valid character" << std::endl;
			std::cout << vector[i] << std::endl;
			contents.clear();EMPTY;
			return INVALID_CHAR;
		}
		contents.push_back(vector[i]);
	}
	std::cout << "Size: " << size << "; ";
	for (int i = 0;i < contents.size();++i) {
		std::cout << contents[i];
	}
	std::cout << std::endl;
	if (contents.size() != size * size) {
		contents.clear();
		size = EMPTY;
		return INVALID_SIZE;
	}

	return SUCCESS;
}

void ImageFile::accept(AbstractFileVisitor* visitor) {
	visitor->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(std::string newName) {
	ImageFile* cloneF = new ImageFile(*this);
	cloneF->name = newName;
	return cloneF;
}