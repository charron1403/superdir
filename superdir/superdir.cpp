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
	if (argc < 2) {
		std::cout << "aucun chemin n'est passe en argument\n";
		return 1;
	}

	struct stat sb;

	fs::directory_entry entry = fs::directory_entry(argv[1]);
	fs::path outfilename = entry.path();
	std::string outfilename_str = outfilename.string();
	const char* path = outfilename_str.c_str();

	if (stat(path, &sb) == 0 && !(sb.st_mode & S_IFDIR)) {
		std::cout << "le chemin specifie n'existe pas\n";
		return 1;
	}

	IFileInfo** fichiers = Functions::FindFiles(argv[1]);
	Functions::RetrieveInformation(fichiers);
	Functions::DisplayInformation(fichiers);

	for (int index = 0; index < 100; index++) {
		std::cout << index << "\tAddress: " << fichiers[index] << "\n";
	}

	delete[] fichiers;
}