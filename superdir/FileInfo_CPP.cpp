#include "FileInfo_CPP.h"
#include <string>
#include <iostream>
#include <algorithm>

FileInfo_CPP::FileInfo_CPP(const char* path) : FileInfo_Text::FileInfo_Text(path) {

}

FileInfo_CPP::~FileInfo_CPP(void) {

}

void FileInfo_CPP::DisplayInformation() {
	std::string filename = mFile;
	std::cout << filename << "\t" << nbLignes << " lignes\tLangage C++ - Fichier source\n";
}