#include "Functions.h"
#include <windows.h>

IFileInfo** Functions::FindFiles(const char * aFolder) {
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	IFileInfo** fichiers = new IFileInfo * [100];
	memset(fichiers, 0, 100 * sizeof(IFileInfo));

	return fichiers;
}