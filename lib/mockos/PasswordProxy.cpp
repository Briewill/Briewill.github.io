#include <iostream>
#include <istream>
#include <sstream>
#include <vector>
#include "../include/mockos/PasswordProxy.h"

PasswordProxy::PasswordProxy(AbstractFile* file, std::string password) : protFile(file), pass(password) {

}

PasswordProxy::~PasswordProxy() {
	delete protFile;
}

std::string PasswordProxy::passwordPrompt() {
	std::string input;
	std::cout << "Enter your password: " << std::endl;
	std::getline(std::cin, input);	

	if (input == pass) {
		return input;
	}
	else {
		std::cout << "Invalid password" << std::endl;
		return "";
	}
}

std::vector<char> PasswordProxy::read() {
	std::string input = passwordPrompt();
	std::vector<char> empty;
	if (input != "") {
		return protFile->read();
	}
	else {
		return empty;
	}
}

int PasswordProxy::write(std::vector<char> vector) {
	std::string input = passwordPrompt();
	if (input != "") {
		protFile->write(vector);
		return SUCCESS;
	}
	else {
		return FAILED;
	}
}

int PasswordProxy::append(std::vector<char> vector) {
	std::string input = passwordPrompt();
	if (input != "") {
		protFile->append(vector);
		return SUCCESS;
	}
	else {
		return FAILED;
	}
}

unsigned int PasswordProxy::getSize() {
	return protFile->getSize();
}

std::string PasswordProxy::getName() {
	return protFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* visitor) {
	std::string input = passwordPrompt();
	if (input != "") {
		protFile->accept(visitor);
	}
}

AbstractFile* PasswordProxy::clone(std::string name) {
	AbstractFile* copy = protFile->clone(name);
	AbstractFile* proxy = new PasswordProxy(copy, pass);
	return proxy;
}