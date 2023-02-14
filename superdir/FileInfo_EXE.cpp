#include "FileInfo_EXE.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <windows.h>

FileInfo_EXE::FileInfo_EXE(const char* path) : FileInfo_Binary::FileInfo_Binary(path){

}

FileInfo_EXE::~FileInfo_EXE(void) {

}

void FileInfo_EXE::DisplayInformation(int maxW) {
	std::string filename = mFile;
	int nbWhitespaces = maxW - filename.length();
	std::string spaces = " ";
	for (int i = 0; i < nbWhitespaces; i++) {
		if ((i % 2) == 0) {
			if ((nbWhitespaces % 2) == 0) {
				spaces += " ";
			}
			else {
				spaces += "-";
			}
		}
		else {
			if ((nbWhitespaces % 2) == 0) {
				spaces += "-";
			}
			else {
				spaces += " ";
			}
		}
	}
	spaces += " ";
	std::string format;
	int finalSize = 0;
	if (nbOctets > 1073741824) {
		format = " Gio";
		finalSize = nbOctets / 1073741824;
	}
	else if (nbOctets > 1048576) {
		format = " Mio";
		finalSize = nbOctets / 1048576;
	}
	else if (nbOctets > 1024) {
		format = " Kio";
		finalSize = nbOctets / 1024;
	}
	else {
		format = " o";
		finalSize = nbOctets;
	}

	std::string sizeS = "" + std::to_string(finalSize) + format;
	int sizeNb = 12 - sizeS.length();
	for (int i = 0; i < sizeNb; i++) {
		sizeS += " ";
	}

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << filename;
	SetConsoleTextAttribute(hConsole, 8);
	std::cout << spaces;
	SetConsoleTextAttribute(hConsole, 6);
	std::cout << sizeS;
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "  Executable\n";
}