#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <set>
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/ImageFile.h"

AbstractFile* SimpleFileFactory::createFile(std::string name) {
	std::string type = name.substr(name.size() - FILE_TYPE, FILE_TYPE);
	if (type == "txt") {
		TextFile* file = new TextFile(name);
		return file;
	}
	else if (type == "img") {
		ImageFile* file = new ImageFile(name);
		return file;
	}
	else {
		return nullptr;
	}
}