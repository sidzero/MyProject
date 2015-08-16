#include "LevelLoader.h"
#include <iostream>
#include<cstdlib>
#include<fstream>

LevelLoader::LevelLoader()
{
}



void LevelLoader::LoadLevel(string FileName)
{

	ifstream inputFile;

	inputFile.open(FileName);
	if (inputFile.fail())
	{
		
		perror("file Loading error");
		system("PAUSE");
	}

	string Line;
	while (getline(inputFile, Line))
	{
		Line[0] = '#';
		Line[Line.size() - 1] = '#';
		Floor.push_back(Line);
	}
};

void LevelLoader::Draw()
{
 
	for (int i = 0; i < Floor.size();i++)
	{
		std::cout << Floor[i]<<endl;
		
	}


};

bool LevelLoader::Update(int x,int y,char symbol,int xp,int yp)
{
	
	switch(Floor[y][x])
	{
	case '#':
		
		return false;
		break;


	case '.':
		Floor[yp][xp] = '.';
		Floor[y][x] = symbol;
		return true;
		break;
	default:
		return false;
		break;
	}

	/*if (false)
	{

		
	}
	else
	{
		Floor[yp][xp] = '.';
		Floor[y][x] = symbol;
		return true;
	}*/
};


