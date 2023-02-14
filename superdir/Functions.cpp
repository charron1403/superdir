#include "Functions.h"
#include <windows.h>
#include <filesystem>
#include <stdio.h>
#include <typeinfo>
#include <iostream>

#include "FileInfo_EXE.h"
#include "FileInfo_Other.h"
#include "FileInfo_H.h"
#include "FileInfo_CPP.h"

namespace fs = std::filesystem;

IFileInfo** Functions::FindFiles(const char * aFolder) {
	

	IFileInfo** fichiers = new IFileInfo * [100];
	memset(fichiers, NULL, 100 * sizeof(IFileInfo));

	struct stat sb;
	int index_file_array = 0;

	for (const auto& entry : fs::directory_iterator(aFolder)) {
		fs::path outfilename = entry.path();
		std::string outfilename_str = outfilename.string();
		const char* path = outfilename_str.c_str();

		if (stat(path, &sb) == 0 && !(sb.st_mode & S_IFDIR) && index_file_array < 100) {
			
			if (outfilename.extension() == ".cpp") {
				fichiers[index_file_array] = new FileInfo_CPP(path);
			}
			else if (outfilename.extension() == ".h") {
				fichiers[index_file_array] = new FileInfo_H(path);
			}
			else if (outfilename.extension() == ".exe") {
				fichiers[index_file_array] = new FileInfo_EXE(path);
			}
			else {
				fichiers[index_file_array] = new FileInfo_Other(path);
			}

			index_file_array++;
		}
	}

	return fichiers;
}

void Functions::RetrieveInformation(IFileInfo** aFiles) {
	for (int i = 0; i < 100; i++) {
		if (aFiles[i] != NULL) {
			aFiles[i]->RetrieveInformation();
		}
	}
}

void Functions::DisplayInformation(IFileInfo** aFiles) {
	int maxW = 0;

	for (int i = 0; i < 100; i++) {
		if (aFiles[i] != NULL) {
			int nbChar = aFiles[i]->GetFilenameLength();
			if (nbChar > maxW) {
				maxW = nbChar;
			}
		}
	}

	for (int i = 0; i < 100; i++) {
		if (aFiles[i] != NULL) {
			aFiles[i]->DisplayInformation(maxW);
		}
	}
}

void Functions::ReleaseMemory(IFileInfo** aFiles) {
	for (int i = 0; i < 100; i++) {
		if (aFiles[i] != NULL) {
			delete aFiles[i];
		}
	}

	delete[] aFiles;
}

int Functions::GetNbFiles(IFileInfo** aFiles) {
	int nbFiles = 0;
	for (int i = 0; i < 100; i++) {
		if (aFiles[i] != NULL) {
			nbFiles++;
		}
	}
	return nbFiles;
}