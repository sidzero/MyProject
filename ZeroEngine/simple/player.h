#pragma once
class player
{
public:
	player();
	~player();
	int x, y, xp,yp,Health,Score;;
	char symbol;
	
	void Init();
	void UpdatePos(char);
	void RevertPos();
	void Display();
	
private:
	

};

