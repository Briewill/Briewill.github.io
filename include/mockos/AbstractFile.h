#pragma once
#include <vector>
#include <string>
class AbstractFileVisitor;

class AbstractFile {
public:
	virtual ~AbstractFile() = default;
	virtual std::vector<char> read() = 0;
	virtual int write(std::vector<char> vector) = 0;
	virtual int append(std::vector<char> vector) = 0;
	virtual void accept(AbstractFileVisitor* visitor) = 0;
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	virtual AbstractFile* clone(std::string name) = 0;
};
enum FilesRet {
	SUCCESS = 0,
	VECT_BORDER = 1,
	INVALID_CHAR = 1,
	INVALID_SIZE = 2,
	EMPTY = 0,
	NOT_ALLOWED
};