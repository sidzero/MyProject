#include "ImageLoader.h"
#include <SOIL\SOIL.h>
#include "Err.h"

namespace nEngine
{



	GLTexture  ImageLoader::loadPNG(const GLchar *fileName)
	{
		GLTexture texture = {};//texture foramt!!!

		//unsigned long width, height;
		// Load image
		int width, height;
		GLuint Internal_Format;
		GLuint Image_Format;
		if (GL_TRUE)//change to alpha for loading transperancy
		{
			Internal_Format = GL_RGBA;
			Image_Format = GL_RGBA;
		}
		unsigned char* image = SOIL_load_image(fileName, &width, &height, 0, Image_Format == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);

		if (image == 0)
		{
			fatalerror("Error loading Texture File");
		}

		texture.width = width;
		texture.height = height;

		glGenTextures(1, &(texture.id));
		glBindTexture(GL_TEXTURE_2D, texture.id);
		//fill it with texture to be send to vram
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);//goes to vram

		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);
		return texture;
	};
};