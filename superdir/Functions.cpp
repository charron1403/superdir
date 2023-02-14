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
			
			if (outfilename.extension() == ".ccp") {
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
			std::cout << (aFiles[i]) << "\n";
			aFiles[i]->RetrieveInformation();
		}
	}
}

void Functions::DisplayInformation(IFileInfo** aFiles) {
	for (int i = 0; i < 2; i++) {
		if (aFiles[i] != NULL) {
			aFiles[i]->DisplayInformation();
		}
	}
}