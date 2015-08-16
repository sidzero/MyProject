#pragma once
#include<string>
#include<vector>
using namespace std;
class LevelLoader
{
public:
	LevelLoader();
	
	vector<string> Floor;

	void LoadLevel(string);
	void Draw();
	bool Update(int,int,char,int,int);
private:

	
};

