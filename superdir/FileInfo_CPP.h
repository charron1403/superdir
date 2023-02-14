#pragma once

#include "FileInfo_Text.h"

class FileInfo_CPP : public FileInfo_Text
{
	public:
		FileInfo_CPP(const char* path);
		~FileInfo_CPP();
		virtual void DisplayInformation(int maxW);
};

