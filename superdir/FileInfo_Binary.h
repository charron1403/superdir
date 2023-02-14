#pragma once

#include "FileInfo_Base.h"

class FileInfo_Binary : public FileInfo_Base
{
	public:
		FileInfo_Binary(const char* path);
		~FileInfo_Binary();
		virtual void RetrieveInformation();

	protected:
		int nbOctets;
};

