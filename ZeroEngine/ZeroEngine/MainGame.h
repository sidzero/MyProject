#pragma once
#include <SDL/SDL.h>
#include <glew\glew.h>

#include "Sprite.h"
#include "GLSLprogram.h"
#include "GLTexture.h"

enum class GameState{PLAY,EXIT};
class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

	

private:
	void initSystems();
	void initShaders();
	void processInput();
	void gameLoop();
	void drawGame();

	SDL_Window* _window;
	int _screenWidth,_screenHeight;
	GameState _gameState;

	Sprite _sprite;
	GLSLprogram _colorProgram;
	float _time;
	GLTexture _playerTexture;
};

