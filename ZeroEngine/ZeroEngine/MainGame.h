#pragma once
#include <SDL/SDL.h>
#include <glew\glew.h>

#include "Sprite.h"
#include "GLSLprogram.h"
#include "GLTexture.h"
#include <vector>

enum class GameState{PLAY,EXIT};
class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

	void calculateFPS();

private:
	void initSystems();
	void initShaders();
	void processInput();
	void gameLoop();
	void drawGame();

	SDL_Window* _window;
	int _screenWidth,_screenHeight;
	GameState _gameState;

	std::vector <Sprite*> _sprites;
	Sprite _sprite;
	GLSLprogram _colorProgram;
	float _time;
	GLTexture _playerTexture;

	float _fps, _frameTime,_maxFPS;
};

