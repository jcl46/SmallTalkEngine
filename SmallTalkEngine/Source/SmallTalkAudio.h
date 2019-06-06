#include <iostream>
using byte = unsigned char;
class AudioFile
{
public:
	std::string _path;
	long _offset;
	long lSize;
	char * buffer;
	size_t result;
	AudioFile(std::string path)
	{
		//Finding And Reading File...
		_path = path;
		FILE * pFile;
		const char* tempPath = _path.c_str();
		pFile = fopen(tempPath, "r");
		fseek(pFile, 0, SEEK_END);
		lSize = ftell(pFile);
		rewind(pFile);
		//YES THIS IS INEFFECTIVE!!!! But for now it will be okay (it loads the whole file into memory)
		buffer = (char*)malloc(sizeof(char)*lSize);
		result = fread(pFile,1,lSize,pFile);
	}
	AudioFile(std::string path, long offset)
	{
		_offset = offset;
		_path = path;
		FILE * pFile;
		const char* tempPath = _path.c_str();
		pFile = fopen(tempPath, "r");
		fseek(pFile, _offset, SEEK_END);
		fseek(pFile, 0, SEEK_END);
		lSize = ftell(pFile);
		rewind(pFile);
		//YES THIS IS INEFFECTIVE!!!! But for now it will be okay (it loads the whole file into memory)
		buffer = (char*)malloc(sizeof(char)*lSize);
		result = fread(pFile, 1, lSize, pFile);
	}
};