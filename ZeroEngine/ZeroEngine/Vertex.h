#pragma once
#include <glew\glew.h>
//multiples of four!!!
struct Position
{
	float x; float y;
};
struct Color
{
	GLubyte r, g, b, a;

};
struct Vertex
{
	Position position;

	Color color;
	

};