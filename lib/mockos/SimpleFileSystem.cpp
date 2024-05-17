#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/ImageFile.h"


SimpleFileSystem::~SimpleFileSystem() {
	for (std::map<std::string, AbstractFile*>::iterator iter = files.begin(); iter != files.end(); ++iter) {
		delete iter->second;
	}
}

int SimpleFileSystem::addFile(std::string name, AbstractFile* file) {
	if (files.find(name) != files.end()) {
		return AR_IN_FILES;
	}
	else if (!file) {
		return NULLPTR_FILE;
	}
	else {
		files.insert({ name, file });
		return SUCCESS;
	}
}
//int SimpleFileSystem::createFile(std::string name) {
//	if (files.find(name) != files.end()) {
//		return AR_IN_FILES;
//	}
//	std::string type = name.substr(name.size() - 3, 3);
//	if (type == "txt") {
//		TextFile *file = new TextFile(name);
//		files.insert({ name, file });
//	}
//	else if (type == "img") {
//		ImageFile* file = new ImageFile(name);
//		files.insert({ name, file });
//	}
//	else {
//		return NOT_A_TYPE;
//	}
//	return SUCCESS;
//}
int SimpleFileSystem::deleteFile(std::string name) {
	auto file_it = files.find(name);
	if (file_it == files.end()) {
		return FILE_DNE;
	}
	AbstractFile* search_file = file_it->second;
	if (openFiles.find(search_file) != openFiles.end()) {
		return AR_OPEN_FILES;
	}
	files.erase(file_it);
	delete search_file;
	return SUCCESS;
}

AbstractFile* SimpleFileSystem::openFile(std::string fileName) {
	auto file_it = files.find(fileName);
	if (file_it == files.end()) {
		return nullptr;
	}
	AbstractFile* search_file = file_it->second;
	if (openFiles.find(search_file) != openFiles.end()) {
		return nullptr;
	}
	openFiles.insert(files[fileName]);
	AbstractFile* p = files[fileName];
	return p;
}

int SimpleFileSystem::closeFile(AbstractFile* file) {
	if (openFiles.find(file) != openFiles.end()) {
		openFiles.erase(file);
		return SUCCESS;
	}
	return FILE_DNE;
}

std::set<std::string> SimpleFileSystem::getFileNames() {
	std::set<std::string> fileNames;
	for (const auto& pair : files) {
		fileNames.insert(pair.first);
	}
	return fileNames;
}

std::map<std::string, AbstractFile*> SimpleFileSystem::getMap() {
	return files;
}
