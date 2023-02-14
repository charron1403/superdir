#pragma once

#include "FileInfo_Base.h"

class FileInfo_Text : public FileInfo_Base
{
	public:
		FileInfo_Text(const char* path);
		~FileInfo_Text();
		virtual void RetrieveInformation();

	protected:
		int nbLignes;
		int GetNbLines(const char * path);
};

