#include "FileInfo_Other.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <windows.h>

FileInfo_Other::FileInfo_Other(const char* path) : FileInfo_Binary::FileInfo_Binary(path) {

}

FileInfo_Other::~FileInfo_Other(void) {

}

void FileInfo_Other::DisplayInformation(int maxW) {
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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << filename;
	SetConsoleTextAttribute(hConsole, 8);
	std::cout << spaces;
	SetConsoleTextAttribute(hConsole, 6);
	std::cout << finalSize << format << "\n";
	SetConsoleTextAttribute(hConsole, 15);
}