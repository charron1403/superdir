#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <filesystem>
#include <string>

#include "Functions.h"
#include "IFileInfo.h"

namespace fs = std::filesystem;


int main(int argc, const char ** argv)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	IFileInfo** fichiers = Functions::FindFiles(argv[1]);

	struct stat sb;

	int index_file_array = 0;

	for (const auto& entry : fs::directory_iterator(argv[1])) {
		fs::path outfilename = entry.path();
		std::string outfilename_str = outfilename.string();
		const char* path = outfilename_str.c_str();

		if (stat(path, &sb) == 0 && !(sb.st_mode & S_IFDIR)) {
			std::cout << path << "\n";
			index_file_array++;
		}
	}

	for (int index = 0; index < 100; index++) {
		std::cout << index << "\tAddress: " << fichiers[index] << "\n";
	}

	delete[] fichiers;
}