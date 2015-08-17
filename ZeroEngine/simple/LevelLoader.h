#pragma once
#include<string>
#include<vector>
#include"player.h"
#include "Monster.h"
using namespace std;
class LevelLoader
{
public:
	LevelLoader();
	
	vector<string> Floor;

	void LoadLevel(string);
	void Draw();
	bool Update(int,int,char,int,int);

	void Update(player&);
	void Update(Monster&);
private:

	
};

