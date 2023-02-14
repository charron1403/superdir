#include "FileInfo_H.h"
#include <iostream>
#include <string>
#include <algorithm>

FileInfo_H::FileInfo_H(const char* path) : FileInfo_Text::FileInfo_Text(path) {

}

FileInfo_H::~FileInfo_H(void) {

}

void FileInfo_H::DisplayInformation() {
	std::string filename = mFile;
	std::cout << filename << "\t" << nbLignes << "\tlignes Langage C/C++ - Fichier entete\n";
}