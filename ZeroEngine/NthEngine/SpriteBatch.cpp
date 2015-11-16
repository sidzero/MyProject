#include "SpriteBatch.h"
#include <algorithm>
namespace nEngine
{
	SpriteBatch::SpriteBatch() :_vbo(0), _vao(0)
	{
	};


	SpriteBatch::~SpriteBatch()
	{
	};

	void SpriteBatch::init()
	{
		createVertexArray();
	};
	void SpriteBatch::Begin(GlyphSortType sortType/*=GlyphSortType::TEXTURE*/)
	{
		_sortType = sortType;
	};
	void SpriteBatch::end()
	{

	};//post procressing like sorting
	void SpriteBatch::draw(const glm::vec4 &destRect, const glm::vec4 &uvRect, const GLuint texture,float depth, const Color &color)
	{
		Glyph *newGlyph = new Glyph();

		newGlyph->texture = texture;
		newGlyph->depth = depth;

		newGlyph->topLeft.setPosition(destRect.x,destRect.y+uvRect.w);
		newGlyph->topLeft.setUV(uvRect.x,uvRect.y+uvRect.w);
		newGlyph->topLeft.color = color;

		newGlyph->bottonLeft.setPosition(destRect.x, destRect.y );
		newGlyph->bottonLeft.setUV(uvRect.x, uvRect.y);
		newGlyph->bottonLeft.color = color;

		newGlyph->bottonRight.setPosition(destRect.x + destRect.z, destRect.y );
		newGlyph->bottonRight.setUV(uvRect.x+uvRect.z, uvRect.y);
		newGlyph->bottonRight.color = color;

		newGlyph->topRight.setPosition(destRect.x+destRect.z, destRect.y + uvRect.w);
		newGlyph->topRight.setUV(uvRect.x, uvRect.y + uvRect.w);
		newGlyph->topRight.color = color;

		glyphs.push_back(newGlyph);
	};//add them to batch

	void SpriteBatch::renderBatch()
	{
	};//draw to screen

	void SpriteBatch::createVertexArray()
	{
		if (_vao == 0)
		{
			glGenVertexArrays(1, &_vao);
		}
		glBindVertexArray(_vao);

		if (_vbo == 0)
		{
			glGenBuffers(1, &_vbo);
		}
		glBindBuffer(GL_ARRAY_BUFFER,_vbo);


		glEnableVertexAttribArray(0);
		//this postion attrinb pointer
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));


		glEnableVertexAttribArray(1);
		//this color attrinb pointer
		glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));


		glEnableVertexAttribArray(2);
		//this uv attrinb pointer
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

		glBindVertexArray(0);


	};

	void SpriteBatch::sortGlyph()
	{
		switch(_sortType)
		{
		case GlyphSortType::BACK_TO_FRONT:

			std::stable_sort(glyphs.begin(),glyphs.end(),compareFrontToBack);

				break;


		case GlyphSortType::FRONT_TO_BACK:
			std::stable_sort(glyphs.begin(), glyphs.end(), compareBackToFront);
			break;

		case GlyphSortType::TEXTURE:
			std::stable_sort(glyphs.begin(), glyphs.end(), compareTexture);
			break;
		default:
			break;
		}
		
	};


	static bool compareFrontToBack(Glyph *a, Glyph *b)
	{
		return (a->depth >b->depth);
	};
	static bool compareBackToFront(Glyph *a, Glyph *b)
	{
		return (a->depth <b->depth);
	};
	static bool compareTexture(Glyph *a, Glyph *b)
	{
		return (a->depth <b->depth);

	};
}