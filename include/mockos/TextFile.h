#pragma once
#include <vector>
#include <string>
#include "AbstractFile.h"

class TextFile : public AbstractFile {
public:
	TextFile(std::string stringName);
	virtual std::vector<char> read();
	virtual int write(std::vector<char> vector);
	virtual int append(std::vector<char> vector);
	virtual void accept(AbstractFileVisitor* visitor) override;
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual AbstractFile* clone(std::string name);
protected:
	std::vector<char> contents;
	std::string name;
};