#include "FileInfo_Binary.h"
#include <string>
#include <fstream>

FileInfo_Binary::FileInfo_Binary(const char* path) {
	nbOctets = 0;

	std::string chemin = path;
	int nbChar = chemin.length();
	for (int i = 0; i < 512; i++) {
		if (i < nbChar) {
			mFolder[i] = path[i];
		}
		else {
			mFolder[i] = NULL;
		}
	}
}

FileInfo_Binary::~FileInfo_Binary(void) {

}

void FileInfo_Binary::RetrieveInformation() {
	std::string chemin = mFolder;
	int filenameIndex = 0;
	for (int i = chemin.length() - 1; i >= 0; i--) {
		if (chemin[i] == '\\') {
			filenameIndex = i + 1;
			break;
		}
	}
	std::string filename = chemin.substr(filenameIndex, chemin.length() - filenameIndex);

	int filenameSize = filename.length();

	for (int i = 0; i < 256; i++) {
		if (i < filenameSize) {
			mFile[i] = filename[i];
		}
		else {
			mFile[i] = NULL;
		}
	}

	std::ifstream file(mFolder, std::ios::binary);
	if (file.fail()) {
		nbOctets = 0;
		return;
	}
	file.seekg(0, std::ios::end);
	nbOctets = file.tellg();
}
