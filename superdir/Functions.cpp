#include "Functions.h"
#include <windows.h>

IFileInfo** Functions::FindFiles(const char * aFolder) {
	

	IFileInfo** fichiers = new IFileInfo * [100];
	memset(fichiers, 0, 100 * sizeof(IFileInfo));

	return fichiers;
}

void RetrieveInformation(IFileInfo** aFiles) {

}