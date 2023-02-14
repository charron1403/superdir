#pragma once

#include "FileInfo_Text.h"

class FileInfo_H : public FileInfo_Text
{
	public:
		FileInfo_H(const char* path);
		~FileInfo_H();
		virtual void DisplayInformation(int maxW);
};

