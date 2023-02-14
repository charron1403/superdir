#include "FileInfo_Text.h"
#include <string>
#include <fstream>

FileInfo_Text::FileInfo_Text(const char * path) {
	nbLignes = 0;

	std::string chemin = path;
	int nbChar = chemin.length();
	for (int i = 0; i < nbChar; i++) {
		mFolder[i] = path[i];
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

	for (int i = 0; i < chemin.length() - filenameIndex; i++) {
		mFile[i] = filename[i];
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