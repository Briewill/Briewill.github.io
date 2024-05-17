#pragma once
#include "../include/mockos/AbstractFileVisitor.h"

class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile* file, std::string password);
	~PasswordProxy();
	virtual std::string passwordPrompt();
	virtual std::vector<char> read();
	virtual int write(std::vector<char> vector);
	virtual int append(std::vector<char> vector);
	virtual void accept(AbstractFileVisitor* visitor) override;
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual AbstractFile* clone(std::string name);
private:
	AbstractFile* protFile;
	std::string pass;
};
enum PROXRET {
	FAILED = 1
};