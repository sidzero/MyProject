
#include "Err.h"
#include <iostream>
#include <SDL\SDL.h>
namespace nEngine
{
	void fatalerror(std::string errorString)
	{
		std::cout << errorString << std::endl;
		std::cout << "press any key to quit";
		int tmp;
		std::cin >> tmp;
		SDL_Quit();
		exit(1);
	};
};