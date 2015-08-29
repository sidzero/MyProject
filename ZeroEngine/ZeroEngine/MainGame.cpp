#include "MainGame.h"

#include <iostream>
#include<string>
void fatalerror(std::string errorString)
{
	std::cout <<errorString<<std::endl ;
	std::cout << "press any key to quit";
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
	exit(1);
}

MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;
}


MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();
	gameLoop();
};

void MainGame::initSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
	if (_window==nullptr)
	{
		fatalerror("SDL window cannot be created");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);

	if (glContext==nullptr)
	{
		fatalerror("Sdl_GL context cannot be created");
	}

	GLenum error= glewInit();
	if (error!=GLEW_OK)
	{
		fatalerror("Could not initialse glew");
	}


	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

	glClearColor(0.5,0.0,0.5,1.0);
};

void  MainGame::processInput()
{
	SDL_Event evnt;

	while(SDL_PollEvent(&evnt))
	{

		switch (evnt.type)
		{

		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout<<evnt.motion.x << " "<<evnt.motion.y<<std::endl;
			break;
		default:
			break;
		}
	}


};

void  MainGame::gameLoop()
{

	while (_gameState!=GameState::EXIT)
	{
		processInput();
		drawGame();
	}

};

//imeedaite mode
void  MainGame::drawGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnableClientState(GL_COLOR_ARRAY);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0,0,0);
	glVertex2f(0,0);
	glVertex2f(0, 5);
	glVertex2f(5, 1);
	glEnd();

	SDL_GL_SwapWindow(_window);


};