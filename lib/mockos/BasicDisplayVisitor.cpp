/**
 * AggregateCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Purpose: This file contains definitions for BasicDisplayVisitor.h.
*/

#include <iostream>
#include "../include/mockos/BasicDisplayVisitor.h"

void BasicDisplayVisitor::visit_TextFile(TextFile* tFile) {
	std::vector<char> contents = tFile->read();
	for (int i = 0; i < contents.size(); ++i) {
		std::cout << contents[i];
	}
	std::cout << std::endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* iFile) {
    int size = iFile->getCharSize();
    std::vector<char> contents = iFile->read();

    unsigned int imgSize = size * size;
    for (int row = size - 1; row >= 0; row--) {
        for (int col = 0; col < size; col++) {
            unsigned int index = size * row + col;
            if (index < contents.size()) {
                std::cout << contents[index];
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}