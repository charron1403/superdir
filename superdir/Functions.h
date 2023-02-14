#pragma once

#include "IFileInfo.h"

class Functions
{
	public:
		static IFileInfo** FindFiles(const char * aFolder);
		static void RetrieveInformation(IFileInfo** aFiles);
		static void DisplayInformation(IFileInfo** aFiles);
		static void ReleaseMemory(IFileInfo** aFiles);
		static int GetNbFiles(IFileInfo** aFiles);
};

