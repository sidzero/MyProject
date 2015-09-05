#include "Camera2D.h"
namespace nEngine
{

	Camera2D::Camera2D() :_needMatrixUpdate(true), _position(0.0f, 0.0f), _cameraMatrix(1.0f), _scale(1.0f), _screenWidth(500), _screenHeight(500), _orthoMatrix(1.0f)
	{
	}


	Camera2D::~Camera2D()
	{
	}



	void Camera2D::init(int screenWidth, int screenHeight)
	{
		_screenHeight = screenHeight;
		_screenWidth = screenWidth;
		_orthoMatrix = glm::ortho(0.0f, (float)_screenWidth, 0.0f, (float)_screenHeight);

	};
	void Camera2D::update()
	{
		if (_needMatrixUpdate)
		{
			
			glm::vec3 translate(-_position.x+(_screenWidth/2.0f), -_position.y+(_screenHeight/2.0f), 0);//oppsite side
			_cameraMatrix = glm::translate(_orthoMatrix, translate);
			glm::vec3 scale(_scale, _scale, 0.0f);
			_cameraMatrix = glm::scale(_cameraMatrix, scale);
			_needMatrixUpdate = false;
		}
	};
};