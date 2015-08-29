//#include <Windows.h>
//#include <SDL/SDL.h>
//
//#include<glew\glew.h>
#include <iostream>
#include "MainGame.h"


int main(int argc,char **argv){

	//SDL_Init(SDL_INIT_EVERYTHING);

	MainGame mainGame;

	mainGame.run();

	return 0;
}
