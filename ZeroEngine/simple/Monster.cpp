#include "Monster.h"
#include <random>


#include<iostream>

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1, 4);//1-north 2-south 3-east 4-west
int dir = distribution(generator);

Monster::Monster()
{
}

void Monster::Init()
{
	x = y = xp = yp = 4;
	Health = 100;
	symbol = '@';
	Score = 0;


};

void Monster::UpdatePos()
{
	dir = distribution(generator);
	switch (dir)
	{
	case 1:
		xp = x;
		yp = y;
		x++;
		break;
	case 2:
		xp = x;
		yp = y;
		x--;
		break;
	case 3:
		xp = x;
		yp = y;
		y--;
		break;
	case 4:
		xp = x;
		yp = y;
		y++;
		break;
	default:
		std::cout << "Wrong Input\n";
		break;
	}
};

void Monster::RevertPos()
{
	x = xp;
	y = yp;
};

void Monster::Display()
{
	std::cout << "Monster Health :" << Health << std::endl;
	std::cout << "Monster Score :" << Score << std::endl;
};
Monster::~Monster()
{
}
