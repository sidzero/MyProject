#include <iostream>

#include <string>
#include<conio.h>
#include "LevelLoader.h"
#include "player.h"
using namespace std;

int main()
{
	player player1;
	LevelLoader level1;

	player1.Init();
	level1.LoadLevel("level1.txt");
	
	
	string s;
	
	level1.Draw();
	player1.Display();
	
	while (true)
	{
		
		s = _getch();
		player1.UpdatePos(s[0]);
		system("CLS");
		if (!level1.Update(player1.x, player1.y, player1.symbol, player1.xp, player1.yp))
		{
			player1.RevertPos();
		}

		level1.Draw();
		player1.Display();
	}

	return 0;
};