#include "FileInfo_Other.h"
#include <string>
#include <iostream>
#include <algorithm>

FileInfo_Other::FileInfo_Other(const char* path) : FileInfo_Binary::FileInfo_Binary(path) {

}

FileInfo_Other::~FileInfo_Other(void) {

}

void FileInfo_Other::DisplayInformation() {
	std::string filename = mFile;
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
	std::cout << filename << "\t" << finalSize << format << "\n";
}