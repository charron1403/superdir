#include "FileInfo_Base.h"
#include <iostream>

FileInfo_Base::FileInfo_Base(void) {

}

FileInfo_Base::~FileInfo_Base(void) {

}

void FileInfo_Base::Init(const char * aFolder, const char * aFile) {

	for (int i = 0; i < 512; i++) {
		mFolder[i] = aFolder[i];
	}
	for (int i = 0; i < 256; i++) {
		mFile[i] = aFile[i];
	}
}
