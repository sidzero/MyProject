#pragma once
#include <glew\glew.h>
//multiples of four!!!
namespace nEngine
{
	struct Position
	{
		float x; float y;
	};
	struct Color
	{
		GLubyte r, g, b, a;

	};

	struct UV
	{
		float u, v;
	};
	struct Vertex
	{
		Position position;

		Color color;

		UV uv;

		void setPosition(float x, float y)
		{
			position.x = x;
			position.y = y;
		}

		void setColor(GLubyte _r, GLubyte _g, GLubyte _b, GLubyte _a)
		{
			color.r = _r;
			color.g = _g;
			color.b = _b;
			color.a = _a;

		};
		void setUV(float U, float V)
		{
			uv.u = U;
			uv.v = V;
		};

	};
};