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

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	IFileInfo** fichiers = Functions::FindFiles(argv[1]); // Find the files
	Functions::RetrieveInformation(fichiers); // Get infos of the files

	std::cout << "\nSuperDir v1.0\n";
	SetConsoleTextAttribute(hConsole, 11);
	std::cout << Functions::GetNbFiles(fichiers);
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << " fichiers trouves dans ";
	SetConsoleTextAttribute(hConsole, 13);
	std::cout << outfilename_str;
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "\n-----------------------------------------------\n\n";


	Functions::DisplayInformation(fichiers); // Display infos of files
	Functions::ReleaseMemory(fichiers); // Clear memory
}