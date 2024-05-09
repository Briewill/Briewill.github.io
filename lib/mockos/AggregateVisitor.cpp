/**
 * AggregateCommand.cpp
 * CSE 332S
 * Lab Num: 5
 * Purpose: This file contains definitions for AggeragateVisitor.h.
*/

#include <iostream>
#include "../include/mockos/AggregateVisitor.h"
#include "../include/mockos/AbstractFile.h"

AggregateVisitor::AggregateVisitor() : numImg(0), numText(0), spaceImg(0), spaceText(0), curLargestImg(0), curLargestText(0) {
	largestText = nullptr;
	largestImg = nullptr;
};

void AggregateVisitor::visit_TextFile(TextFile* file) {
	numText++;
	int size = file->getSize();
	spaceText += size;
	if (size >= curLargestText) {
		largestText = file;
		curLargestText = size;
	}
}

void AggregateVisitor::visit_ImageFile(ImageFile* file) {
	numImg++;
	int size = file->getSize();
	spaceImg += size;
	if (size >= curLargestImg) {
		largestImg = file;
		curLargestImg = size;
	}
}

void AggregateVisitor::print_all() {
	int totalNum = numText + numImg;
	int totalSize = spaceText + spaceImg;

	//count data
	std::cout << "Total Number of Files: " << totalNum << std::endl;
	std::cout << "Number of Text Files: " << numText << std::endl;
	std::cout << "Number of Image Files: " << numImg << std::endl;

	//size data
	std::cout << "Total Space Occupied by Files: " << totalSize << std::endl;
	std::cout << "Space Occupied by Text Files: " << spaceText << std::endl;
	std::cout << "Space Occupied by Image Files: " << spaceImg << std::endl;

	//largest text and largest image
	if (largestText == nullptr && largestImg != nullptr) {
		std::cout << "Largest Text File: N/A" << std::endl;
		std::cout << "Largest Image File: " << largestImg->getName() << std::endl;
	}
	else if (largestImg == nullptr && largestText != nullptr) {
		std::cout << "Largest Text File: " << largestText->getName() << std::endl;
		std::cout << "Largest Image File: N/A" << std::endl;

	}
	else {
		std::cout << "Largest Text File: " << largestText->getName() << std::endl;
		std::cout << "Largest Image File: " << largestImg->getName() << std::endl;
	}
}

void AggregateVisitor::print_counts() {
	int totalNum = numText + numImg;

	std::cout << "Total Number of Files: " << totalNum << std::endl;
	std::cout << "Number of Text Files: " << numText << std::endl;
	std::cout << "Number of Image Files: " << numImg << std::endl;
}

void AggregateVisitor::print_sizes() {
	int totalSize = spaceText + spaceImg;

	//size data
	std::cout << "Total Space Occupied by Files: " << totalSize << std::endl;
	std::cout << "Space Occupied by Text Files: " << spaceText << std::endl;
	std::cout << "Space Occupied by Image Files: " << spaceImg << std::endl;

	//printing the largest
	if (largestText == nullptr && largestImg != nullptr) {
		std::cout << "Largest Text File: N/A" << std::endl;
		std::cout << "Largest Image File: " << largestImg->getName() << std::endl;
	}
	else if (largestImg == nullptr && largestText != nullptr) {
		std::cout << "Largest Text File: " << largestText->getName() << std::endl;
		std::cout << "Largest Image File: N/A" << std::endl;

	}
	else {
		std::cout << "Largest Text File: " << largestText->getName() << std::endl;
		std::cout << "Largest Image File: " << largestImg->getName() << std::endl;
	}
}

void AggregateVisitor::reset() {
	numImg = 0;
	numText = 0;
	spaceImg = 0;
	spaceText = 0;

	largestImg = nullptr;
	largestText = nullptr;
	curLargestImg = 0;
	curLargestText = 0;
}