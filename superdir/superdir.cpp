#include <iostream>
#include <stdio.h>

#include "Functions.h"
#include "IFileInfo.h"


int main(int argc, const char ** argv)
{
	IFileInfo** fichiers = Functions::FindFiles(argv[1]);

	for (int index = 0; index < 100; index++) {
		std::cout << index << " Address: " << fichiers[index] << "\n";
	}

	delete[] fichiers;
}