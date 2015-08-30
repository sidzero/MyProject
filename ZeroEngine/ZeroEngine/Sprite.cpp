#include "Sprite.h"
#include "Vertex.h"
#include<cstddef>
Sprite::Sprite()
{
	_vboID = 0;
}


Sprite::~Sprite()
{
	if (_vboID!=0)
	{
		glDeleteBuffers(1,&_vboID);
	}
}
void Sprite::init(float x, float y, float width, float height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	if (_vboID == 0)
	{
		glGenBuffers(1,&_vboID);
	}
	//screen codrinates bottom left start at 0,0
	//GLfloat vertexData[12];

	Vertex vertexData[6];

	//firt traingle
	/*vertexData[0].position.x = x + width;
	vertexData[0].position.y = y + height;*/

	vertexData[0].setPosition(x + width, y + height);
	vertexData[0].setUV(1.0f,1.0f);

	/*vertexData[1].position.x = x;
	vertexData[1].position.y = y + height;*/

	vertexData[1].setPosition(x, y + height);
	vertexData[1].setUV(0.0f, 1.0f);

	/*vertexData[2].position.x = x;
	vertexData[2].position.y = y;*/

	vertexData[2].setPosition(x, y);
	vertexData[2].setUV(0.0f, 0.0f);

	//secind
	//vertexData[3].position.x = x ;
	//vertexData[3].position.y = y ;

	vertexData[3].setPosition(x, y);
	vertexData[3].setUV(0.0f, 0.0f);
/*
	vertexData[4].position.x = x+width;
	vertexData[4].position.y = y;*/

	vertexData[4].setPosition(x+width, y);
	vertexData[4].setUV(1.0f, 0.0f);

	/*vertexData[5].position.x = x+width;
	vertexData[5].position.y = y+height;*/

	vertexData[5].setPosition(x + width, y+height);
	vertexData[5].setUV(1.0f, 1.0f);

	for (int i = 0; i < 6;i++)
	{
		vertexData[i].color.r = 255;
		vertexData[i].color.g = 0;
		vertexData[i].color.b = 255;
		vertexData[i].color.a = 255;
	}

	vertexData[1].setColor(255, 0, 0, 255);
	vertexData[4].setColor(0,255,0,255);

	glBindBuffer(GL_ARRAY_BUFFER,_vboID);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertexData),vertexData,GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER,0);



};

void  Sprite::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER,_vboID);

	glEnableVertexAttribArray(0);
	//this postion attrinb pointer
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,sizeof(Vertex), (void*)offsetof(Vertex,position));


	glEnableVertexAttribArray(1);
	//this color attrinb pointer
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));


	glEnableVertexAttribArray(2);
	//this uv attrinb pointer
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));


	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER,0);
};