#pragma once

#include "FileInfo_Base.h"

class FileInfo_Text : public FileInfo_Base
{
	public:
		FileInfo_Text();
		~FileInfo_Text();
		virtual void RetrieveInformation(const char * path);

	private:
		int nbLignes;
};

