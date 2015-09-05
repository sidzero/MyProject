#include "MainGame.h"
#include <NthEngine\NEngine.h>
#include <iostream>
#include<string>
#include <NthEngine\Err.h>
#include <NthEngine\ImageLoader.h>


MainGame::MainGame() :_window(), _screenWidth(1024), _screenHeight(768), _gameState(GameState::PLAY), _time(0), _maxFPS(60.0f)
{
	_camera.init(_screenWidth,_screenHeight);
}


MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems();


	//_sprite.init(-1.0f, -1.0f, 2.0f, 2.0f, "Texture/PNG/CharacterRight_Standing.png");

	_sprites.push_back(new nEngine::Sprite());
	_sprites.back()->init(0, 0, 500.0f,500.0f, "Texture/PNG/CharacterRight_Standing.png");


	//_sprites.push_back(new nEngine::Sprite());
	//_sprites.back()->init(0.0f, -1.0f, 1.0f, 1.0f, "Texture/PNG/CharacterRight_Standing.png");

	//_sprites.push_back(new nEngine::Sprite());
	//_sprites.back()->init(0.0f, 0.0f, 1.0f, 1.0f, "Texture/PNG/CharacterRight_Standing.png");

	//_sprites.push_back(new nEngine::Sprite());
	//_sprites.back()->init(-1.0f, 0.0f, 1.0f, 1.0f, "Texture/PNG/CharacterRight_Standing.png");

	
	//_playerTexture= ImageLoader::loadPNG("Texture/PNG/CharacterRight_Standing.png");

	gameLoop();
};

void MainGame::initSystems()
{
	/*SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);*/
	_window.create("Game Engine",_screenWidth,_screenHeight,0);
	initShaders();
};


void MainGame::initShaders()
{
	_colorProgram.compileShaders("Shaders/CameraTextureShading.vert", "Shaders/CameraTextureShading.frag");
	_colorProgram.addAttribute("vertexPosition");//chk the shader
	_colorProgram.addAttribute("vertexColor");
	_colorProgram.addAttribute("vertexUV");

	_colorProgram.linkShaders();
};
void  MainGame::processInput()
{
	SDL_Event evnt;
	const float CAMERA_SPEED = 20.0f, SCALE_SPEED = 0.01f; float scaleT;
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

		case SDL_KEYDOWN:
			switch (evnt.key.keysym.sym)
			{
			case SDLK_w:
				_camera.setPosition(_camera.getPosition() + glm::vec2(0.0f, -CAMERA_SPEED));
				break;
			case SDLK_s:
				_camera.setPosition(_camera.getPosition() + glm::vec2(0.0f, CAMERA_SPEED));
				break;
			case SDLK_a:
				_camera.setPosition(_camera.getPosition() + glm::vec2(CAMERA_SPEED, 0));
				break;
			case SDLK_d:
				_camera.setPosition(_camera.getPosition() + glm::vec2(-CAMERA_SPEED,0.0f));
				break;

			case SDLK_q:
				scaleT = _camera.getScale() - SCALE_SPEED;
				_camera.setScale(scaleT);
				break;
			case SDLK_e:
				 scaleT = _camera.getScale() + SCALE_SPEED;
				_camera.setScale(scaleT);
				break;


			default:
				break;
			}
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

		_camera.update();
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

	GLint pLocation = _colorProgram.getUniformLocation("P");

	glUniform1i(textureLocation,0);
	glUniform1f(timeLocation,_time);

	glm::mat4 cameraMatrix = _camera.getCameraMatrix();
	glUniformMatrix4fv(pLocation,1,GL_FALSE,&(cameraMatrix[0][0]));

	//_sprite.draw();

	for (int i = 0; i < _sprites.size();i++)
	{
		_sprites[i]->draw();
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	_colorProgram.unUse();
	_window.swapBuffer();
	

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