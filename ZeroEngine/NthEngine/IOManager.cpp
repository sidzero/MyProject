#include "IOManager.h"
#include<fstream>

bool IOManager::readFileToBuffer(std::string filePath, std::vector<unsigned char> &buffer)
{
	std::ifstream file(filePath, std::ios::binary);//readin in binary format in 1's 0 's;

	if (file.fail())
	{
		perror(filePath.c_str());
		return false;
	}

	//determine file size
	file.seekg(0,std::ios::end);//put cursor at end

	int fileSize = file.tellg();//how many bytes before currrent locations
	file.seekg(0, std::ios::beg);//set it back at start

	//reduce file size by any header it mightr have
	fileSize -= file.tellg();

	buffer.resize(fileSize);

	file.read((char *)&(buffer[0]),fileSize);

	file.close();

	return true;

};


