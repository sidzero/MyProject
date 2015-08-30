#pragma once
#include<vector>
#include<string>
class IOManager
{
public:
	//this func will fill data
	static bool readFileToBuffer(std::string filePath,std::vector<unsigned char> &buffer);
};

