#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
namespace nEngine
{
	class Camera2D
	{
	public:
		Camera2D();
		~Camera2D();

		void init(int, int);
		void update();

		//getter setters
		void setPosition(glm::vec2& newPosition)
		{
			_position = newPosition;
			_needMatrixUpdate = true;
		};
		glm::vec2 getPosition(){ return _position; };

		void setScale(float &newScale){ _scale = newScale; _needMatrixUpdate = true; };
		float getScale(){ return _scale; };

		glm::mat4 getCameraMatrix(){ return _cameraMatrix; };

	private:
		int _screenWidth, _screenHeight;
		bool _needMatrixUpdate;
		float _scale;
		glm::vec2 _position;
		glm::mat4 _cameraMatrix;
		glm::mat4 _orthoMatrix;
	};

};