#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>

TextureCache::TextureCache()
{
}


TextureCache::~TextureCache()
{
};

GLTexture TextureCache::getTexture(std::string texturePath)
{
	//check if its in map
	auto mit= _textureMap.find(texturePath);

	if (mit==_textureMap.end())
	{
		GLTexture newTexture = ImageLoader::loadPNG(texturePath.c_str());

		//std::pair<std::string, GLTexture> newPair(texturePath, newTexture);
		_textureMap.insert(make_pair(texturePath, newTexture));
		std::cout <<"New Texture add to cache" ;
		return newTexture;
	}
	std::cout << "Loading from ccahe";
	return mit->second;
};
