#pragma once
#include <SDL/SDL.h>
#include <glew\glew.h>


enum class GameState{PLAY,EXIT};
class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

	

private:
	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();

	SDL_Window* _window;
	int _screenWidth,_screenHeight;
	GameState _gameState;

};

