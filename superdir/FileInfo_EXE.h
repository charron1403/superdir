#pragma once

#include "FileInfo_Binary.h"

class FileInfo_EXE : public FileInfo_Binary
{
	public:
		FileInfo_EXE();
		~FileInfo_EXE();
		virtual void DisplayInformation();
};

