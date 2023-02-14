#include "FileInfo_Text.h"
#include <string>
#include <fstream>

FileInfo_Text::FileInfo_Text(const char * path) {
	nbLignes = 0;

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

FileInfo_Text::~FileInfo_Text(void) {

}

void FileInfo_Text::RetrieveInformation() {
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

	nbLignes = GetNbLines(mFolder);
}



int FileInfo_Text::GetNbLines(const char * path) {
	std::ifstream file;
	file.open(path);
	if (file.fail()) {
		file.close();
		return 0;
	}
	std::string line;
	int nb = 0;
	while (std::getline(file, line)) {
		nb++;
	}
	return nb;
}