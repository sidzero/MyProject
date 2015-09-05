#include <SDL\SDL.h>
#include <glew\glew.h>
#include "NEngine.h"
namespace nEngine
{
	int init()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		return 0;
	};
};