#include "MainGame.h"

#include <iostream>
#include<string>
#include "Error.h"
#include "ImageLoader.h"


MainGame::MainGame() :_window(nullptr), _screenWidth(1024), _screenHeight(768), _gameState(GameState::PLAY), _time(0), _maxFPS(60.0f)
{
	
}


MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();


	_sprite.init(-1.0f, -1.0f, 2.0f, 2.0f, "Texture/PNG/CharacterRight_Standing.png");

	_sprites.push_back(new Sprite());
	_sprites.back()->init(-1.0f, -1.0f, 1.0f, 1.0f, "Texture/PNG/CharacterRight_Standing.png");


	_sprites.push_back(new Sprite());
	_sprites.back()->init(0.0f, -1.0f, 1.0f, 1.0f, "Texture/PNG/CharacterRight_Standing.png");


	
	//_playerTexture= ImageLoader::loadPNG("Texture/PNG/CharacterRight_Standing.png");

	gameLoop();
};

void MainGame::initSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

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
	glewExperimental = true;
	GLenum error= glewInit();
	if (error!=GLEW_OK)
	{
		fatalerror("Could not initialse glew");
	}


	glClearColor(0.5,0.0,0.5,1.0);

	SDL_GL_SetSwapInterval(0);

	initShaders();
	std::printf("**** opengl version %s *****\n",glGetString(GL_VERSION));
};


void MainGame::initShaders()
{
	_colorProgram.compileShaders("Shaders/TextureShading.vert", "Shaders/TextureShading.frag");
	_colorProgram.addAttribute("vertexPosition");//chk the shader
	_colorProgram.addAttribute("vertexColor");
	_colorProgram.addAttribute("vertexUV");

	_colorProgram.linkShaders();
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
			//std::cout<<evnt.motion.x << " "<<evnt.motion.y<<std::endl;
			break;
		default:
			break;
		}
	}


};

void  MainGame::gameLoop()
{

	while (_gameState != GameState::EXIT)
	{
		//frame time measure
		float startTicks = SDL_GetTicks();
		processInput();
		drawGame();
		_time += 0.1f;
		calculateFPS();
		//print olny once every 10 frames
		static int frameCounter = 0;
		if (frameCounter == 10)
		{
			std::cout << _fps << std::endl;
			frameCounter = 0;
		}
		frameCounter++;

		float frameTicks = SDL_GetTicks() - startTicks;
		//limiting fps 
		if (1000.0f/_maxFPS >frameTicks)
		{
			SDL_Delay((1000.0f/_maxFPS)-frameTicks);
		}
	}

};

//imeedaite mode
void  MainGame::drawGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/*//imeediate mode
	glEnableClientState(GL_COLOR_ARRAY);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0,0,0);
	glVertex2f(-1,-1);
	glVertex2f(0, -1);
	glVertex2f(0, 0);
	glEnd();*/


	_colorProgram.use();
	glActiveTexture(GL_TEXTURE0);
	
	
	GLint timeLocation=_colorProgram.getUniformLocation("time");
	GLint textureLocation = _colorProgram.getUniformLocation("mySampler");
	glUniform1i(textureLocation,0);
	glUniform1f(timeLocation,_time);
	//_sprite.draw();

	for (int i = 0; i < _sprites.size();i++)
	{
		_sprites[i]->draw();
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	_colorProgram.unUse();
	SDL_GL_SwapWindow(_window);
	

};
void MainGame::calculateFPS()
{
	static const int NUM_SAMPLES = 10;
	static float frameTime[NUM_SAMPLES];
	static int currentFrame = 0;

	static float prevTicks = SDL_GetTicks();
	float currentTicks;

	currentTicks = SDL_GetTicks();
	_frameTime = currentTicks - prevTicks;

	prevTicks = currentTicks;
	int count;
	currentFrame++;
	frameTime[currentFrame%NUM_SAMPLES] = _frameTime;

	if (currentFrame<NUM_SAMPLES)
	{
		count = currentFrame;
	}
	else
	{
		count = NUM_SAMPLES;
	}

	float frameTimeAverage=0;
	for (int i = 0; i < count; i++)
	{
		frameTimeAverage += frameTime[i];
	}
	frameTimeAverage /= count;
	if (frameTimeAverage>0)
	{
		_fps = 1000 / frameTimeAverage;
	}
	else
	{
		_fps = 70;
	}


};