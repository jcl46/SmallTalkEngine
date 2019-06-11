#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory_resource>

//Admiting defeat and using the windows headers... I really wanted to avoid them to make it possible to create games for linux or mac...
#include "windows.h"
#include "mmsystem.h"
using byte = unsigned char;
#pragma warning(disable : 4996)

class AudioSource
{
public:
	std::string _path;
	//long _offset;
	//long lSize;
	char * buffer;
	//size_t result;
	std::ifstream file;
	int size;
	AudioSource(std::string path)
	{
		/* 
		This part has been commented, due to it being unreliable and written as C - The new version using C++ is far better

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
		result = fread(buffer, lSize, 1, pFile);
		fclose(pFile);
		*/

		_path = path;
		file = std::ifstream (_path, std::ios::binary);
		file.seekg(0, std::ios::end);
		size = file.tellg();
		file.seekg(0, std::ios::beg);

		buffer = new char[size];
		file.read(buffer, size);
		file.close();
	}
	AudioSource(std::string path, long offset)
	{
		/*
		This part has been commented, due to it being unreliable and written as C - The new version using C++ is far better

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
		result = fread(buffer, 1, lSize, pFile);
		fclose(pFile);
		*/
		_path = path;
		file = std::ifstream(_path, std::ios::binary);
		size = file.tellg();
		file.seekg(0, std::ios::beg);

		buffer = new char[size];
		file.read(buffer, size);
		file.close();
	}
	void Play()
	{
		HINSTANCE HInstance = GetModuleHandle(0);
		PlaySound(NULL, 0, 0);
		size_t raw;
		file.close();
		
		bool player = PlaySound(buffer, HInstance, SND_MEMORY);
		if (!player)
		{
			std::cout << "Error playing file..." << std::endl;
		}
		else
		{
			std::cout << "File Loaded correctly to memory :)" << std::endl;
		}
		
		//This line is just a debug
		//PlaySoundA(buffer,HInstance,SND_MEMORY);
		free(buffer);
	}
};

/*
class StreamingAudio
{
public:
	const char* _path;
	long _offset;
	long lSize;
	char * buffer;
	size_t result;
	long tempOffset;
	StreamingAudio(std::string path)
	{
		tempOffset = 0;
		_path = path.c_str();
		FILE * pFile;
		pFile = fopen(_path,"r");
		fseek(pFile, 0, SEEK_END);
		lSize = ftell(pFile);
		rewind(pFile);
		buffer = (char*)malloc(sizeof(char)*lSize/4);
		_offset = sizeof(char)*lSize / 4;
		fseek(pFile,tempOffset,_offset);
		lSize = ftell(pFile);
		rewind(pFile);
		fread(buffer, 1, lSize, pFile);
		unsigned char dataToPlay = *buffer;
		//Insert play of buffer here...
		tempOffset = lSize * 2;
		fseek(pFile, _offset, tempOffset);
		lSize = ftell(pFile);
	}
};
*/