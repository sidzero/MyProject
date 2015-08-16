#include "player.h"
#include<iostream>

player::player()
{
}

void player::Init()
{
	x = y = xp=yp=5;
	Health = 100;
	symbol = 'X';
	Score = 0;


};

void player::UpdatePos(char dir)
{
	switch (dir)
	{
	case 'd':
		xp = x;
		yp = y;
		x++;
		break;
	case 'a':
		xp = x;
		yp = y;
		x--;
			break;
	case 'w':
		xp = x;
		yp = y;
		y--;
		break;
	case 's':
		xp = x;
		yp = y;
		y++;
		break;
	default:
		std::cout << "Wrong Input\n";
		break;
	}
};

void player::RevertPos()
{
	x = xp;
	y = yp;
};

void player::Display()
{
	std::cout << "Player Health :" << Health << std::endl;
	std::cout << "Player Score :" << Score << std::endl;
};
player::~player()
{
}
