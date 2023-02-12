#pragma once

#include "FileInfo_Base.h"

class FileInfo_Binary : public FileInfo_Base
{
	public:
		FileInfo_Binary();
		~FileInfo_Binary();
		virtual void RetrieveInformation(const char* path);

	private:
		int nbOctets;
};

