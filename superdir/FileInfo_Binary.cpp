#include "FileInfo_Binary.h"
#include <string>

FileInfo_Binary::FileInfo_Binary(void) {
	nbOctets = 0;
}

FileInfo_Binary::~FileInfo_Binary(void) {

}

void FileInfo_Binary::RetrieveInformation(const char* path) {
	std::string chemin = path;
	int nbChar = chemin.length();
	for (int i = 0; i < nbChar; i++) {
		mFolder[i] = path[i];
	}
	int filenameIndex = 0;
	for (int i = chemin.length() - 1; i >= 0; i--) {
		if (chemin[i] == '\\') {
			filenameIndex = i + 1;
			break;
		}
	}
	std::string filename = chemin.substr(filenameIndex, chemin.length() - filenameIndex);

	for (int i = 0; i < chemin.length() - filenameIndex; i++) {
		mFile[i] = filename[i];
	}
}
