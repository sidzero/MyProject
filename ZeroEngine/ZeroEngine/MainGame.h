#pragma once
#include <SDL/SDL.h>
#include <glew\glew.h>

#include <NthEngine\Sprite.h>
#include <NthEngine\GLSLprogram.h>
#include <NthEngine\GLTexture.h>
#include <vector>
#include <NthEngine\Window.h>
#include <NthEngine\Camera2D.h>

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

	nEngine::Window _window;
	int _screenWidth,_screenHeight;
	GameState _gameState;

	std::vector <nEngine::Sprite*> _sprites;
	nEngine::Sprite _sprite;
	nEngine::GLSLprogram _colorProgram;
	float _time;
	nEngine::GLTexture _playerTexture;

	float _fps, _frameTime,_maxFPS;

	nEngine::Camera2D _camera;
	
};

