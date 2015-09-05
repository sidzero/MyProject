#include "Window.h"
#include "Err.h"

namespace nEngine
{
	Window::Window()
	{
	}


	Window::~Window()
	{
	}
	int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags)
	{
		Uint32 flags = SDL_WINDOW_OPENGL;
		if (currentFlags & INVISIBLE)
		{
			flags |= SDL_WINDOW_HIDDEN;
		}

		if (currentFlags & FULLSCREEN)
		{
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		}
		if (currentFlags & INVISIBLE)
		{
			flags |= SDL_WINDOW_BORDERLESS;
		}
		_sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);
		if (_sdlWindow == nullptr)
		{
			fatalerror("SDL window cannot be created");
		}

		SDL_GLContext glContext = SDL_GL_CreateContext(_sdlWindow);

		if (glContext == nullptr)
		{
			fatalerror("Sdl_GL context cannot be created");
		}
		glewExperimental = true;
		GLenum error = glewInit();
		if (error != GLEW_OK)
		{
			fatalerror("Could not initialse glew");
		}


		glClearColor(0.5, 0.0, 0.5, 1.0);

		SDL_GL_SetSwapInterval(0);


		std::printf("**** opengl version %s *****\n", glGetString(GL_VERSION));

		return 0;
	};
	void Window::swapBuffer()
	{
		SDL_GL_SwapWindow(_sdlWindow);
	};

};