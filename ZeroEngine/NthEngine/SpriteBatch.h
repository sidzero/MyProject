#pragma once
#include <glew\glew.h>
#include "Vertex.h"
#include <vector>
#include <glm\glm.hpp>
namespace nEngine
{
	enum class GlyphSortType
	{
	NONE,
	FRONT_TO_BACK,
	BACK_TO_FRONT,
	TEXTURE,
	};


	struct Glyph
	{
		GLuint texture;
		float depth;

		Vertex topLeft;
		Vertex bottonLeft;
		Vertex topRight;
		Vertex bottonRight;
	};
	class SpriteBatch
	{
	public:
		SpriteBatch();
		~SpriteBatch();

		void init();
		void Begin(GlyphSortType sortType);
		void end();//post procressing like sorting
		void draw(const glm::vec4 &destRect,const glm::vec4 &uvRect,const GLuint texture,float depth,const Color &color);//add them to batch

		void renderBatch();//draw to screen

	private:
		void createVertexArray();
		void sortGlyph();

		static bool compareFrontToBack(Glyph *a,Glyph *b);
		static bool compareBackToFront(Glyph *a, Glyph *b);
		static bool compareTexture(Glyph *a, Glyph *b);
		
		
		GlyphSortType _sortType;
		GLuint _vbo;
		GLuint _vao;
		std::vector<Glyph*> glyphs;//called from draw

	};
};
