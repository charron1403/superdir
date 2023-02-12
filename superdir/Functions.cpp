#include "Functions.h"
#include <windows.h>
#include <filesystem>
#include <stdio.h>

#include "FileInfo_EXE.h"
#include "FileInfo_Other.h"
#include "FileInfo_H.h"
#include "FileInfo_CPP.h"

namespace fs = std::filesystem;

IFileInfo** Functions::FindFiles(const char * aFolder) {
	

	IFileInfo** fichiers = new IFileInfo * [100];
	memset(fichiers, 0, 100 * sizeof(IFileInfo));

	struct stat sb;
	int index_file_array = 0;

	for (const auto& entry : fs::directory_iterator(aFolder)) {
		fs::path outfilename = entry.path();
		std::string outfilename_str = outfilename.string();
		const char* path = outfilename_str.c_str();

		if (stat(path, &sb) == 0 && !(sb.st_mode & S_IFDIR) && index_file_array < 100) {
			
			if (outfilename.extension() == ".ccp") {
				fichiers[index_file_array] = new FileInfo_CPP();
			}
			else if (outfilename.extension() == ".h") {
				fichiers[index_file_array] = new FileInfo_H();
			}
			else if (outfilename.extension() == ".exe") {
				fichiers[index_file_array] = new FileInfo_EXE();
			}
			else {
				fichiers[index_file_array] = new FileInfo_Other();
			}

			fichiers[index_file_array]->RetrieveInformation(path);

			index_file_array++;
		}
	}

	return fichiers;
}

void RetrieveInformation(IFileInfo** aFiles) {

}