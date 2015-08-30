#pragma once
#include <glew\glew.h>
//multiples of four!!!
struct Vertex
{
	struct Position
	{
		float x; float y;
	}position;

	struct Color
	{
		GLubyte r,g,b,a;

	}color;
	

};