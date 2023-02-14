#include "FileInfo_CPP.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <windows.h>

FileInfo_CPP::FileInfo_CPP(const char* path) : FileInfo_Text::FileInfo_Text(path) {

}

FileInfo_CPP::~FileInfo_CPP(void) {

}

void FileInfo_CPP::DisplayInformation(int maxW) {
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

	std::string nbLignesS = std::to_string(nbLignes) + " lignes";
	int nbLignesNb = 12 - nbLignesS.length();
	for (int i = 0; i < nbLignesNb; i++) {
		nbLignesS += " ";
	}
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << filename;
	SetConsoleTextAttribute(hConsole, 8);
	std::cout << spaces;
	SetConsoleTextAttribute(hConsole, 6);
	std::cout << nbLignesS;
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "  Langage C++ - Fichier source\n";
}