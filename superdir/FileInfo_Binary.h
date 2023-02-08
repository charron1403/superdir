#pragma once

#include "FileInfo_Base.h"

class FileInfo_Binary : FileInfo_Base
{
	public:
		FileInfo_Binary(void);
		~FileInfo_Binary(void);
		virtual void RetrieveInformation();
};

