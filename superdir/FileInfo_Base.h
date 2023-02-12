#pragma once

#include "IFileInfo.h"

class FileInfo_Base : public IFileInfo
{
	public:
		FileInfo_Base(void);
		~FileInfo_Base(void);
		virtual void Init(const char* aFolder, const char* aFile);

	protected:
		char mFolder[512];
		char mFile[256];
};

