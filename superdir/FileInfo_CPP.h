#pragma once

#include "FileInfo_Text.h"

class FileInfo_CPP : public FileInfo_Text
{
	public:
		FileInfo_CPP();
		~FileInfo_CPP();
		virtual void DisplayInformation();
};

