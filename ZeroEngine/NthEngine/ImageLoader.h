#pragma once
#include "GLTexture.h"
#include <string>
namespace nEngine
{
	class ImageLoader
	{
	public:
		static GLTexture loadPNG(const GLchar *fileName);



	};
}