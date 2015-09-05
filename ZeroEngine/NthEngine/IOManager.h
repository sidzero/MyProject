#pragma once
#include<vector>
#include<string>
namespace nEngine
{
	class IOManager
	{
	public:
		//this func will fill data
		static bool readFileToBuffer(std::string filePath, std::vector<unsigned char> &buffer);
	};

};