#pragma once
#include <SDL\SDL.h>
#include<glew\glew.h>
#include <string>
class Window
{
public:
	Window();
	~Window();

	int create(std::string windowName);
private:
	SDL_Window * _sdlWindow;
};

