#include "FileInfo_H.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

FileInfo_H::FileInfo_H(const char* path) : FileInfo_Text::FileInfo_Text(path) {

}

FileInfo_H::~FileInfo_H(void) {

}

void FileInfo_H::DisplayInformation(int maxW) {
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
	std::cout << "  Langage C/C++ - Fichier entete\n";
}