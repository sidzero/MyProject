#pragma once
#include <glew\glew.h>
#include "GLTexture.h"
#include <string>
namespace nEngine
{
	class Sprite
	{
	public:
		Sprite();
		~Sprite();

		void init(float x, float y, float width, float height, std::string texturePath);
		void draw();
	private:
		int _x, _y, _width, _height;

		GLuint _vboID;
		GLTexture _texture;
	};

};