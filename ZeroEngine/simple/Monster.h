#pragma once
class Monster
{
public:
	Monster();
	~Monster();
	int x, y, xp, yp, Health, Score;;
	char symbol;

	void Init();
	void UpdatePos();
	void RevertPos();
	void Display();



private:
};

