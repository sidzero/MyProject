#include <iostream>

#include <string>
#include<conio.h>
#include<vector>
#include "LevelLoader.h"
#include "player.h"
#include "Monster.h"
using namespace std;

int main()
{
	vector<Monster> monsters;
	player player1;
	for (int i = 0; i < 5; i++)
	{
		Monster monster;
		monster.Init();
		monster.x += 2*i;
		monsters.push_back(monster);
	}
	LevelLoader level1;

	player1.Init();
	
	level1.LoadLevel("level1.txt");
	
	
	string s;
	
	level1.Draw();
	player1.Display();

	for (int i = 0; i < monsters.size(); i++)
	monsters[i].Display();
	
	while (true)
	{
		
		s = _getch();

		for (int i = 0; i < monsters.size(); i++)
		monsters[i].UpdatePos();
		player1.UpdatePos(s[0]);
		system("CLS");
		for (int i = 0; i < monsters.size(); i++)
		if (!level1.Update(monsters[i].x, monsters[i].y, monsters[i].symbol, monsters[i].xp, monsters[i].yp))
		{
			monsters[i].RevertPos();
		}

		if (!level1.Update(player1.x, player1.y, player1.symbol, player1.xp, player1.yp))
		{
			player1.RevertPos();
		}

		level1.Draw();
		player1.Display();
		/*for (int i = 0; i < monsters.size(); i++)
		monsters[i].Display();*/
	}

	return 0;
};