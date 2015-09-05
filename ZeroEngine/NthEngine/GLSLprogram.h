#pragma once
#include <glew\glew.h>
#include <string>
namespace nEngine
{
	class GLSLprogram
	{
	public:
		GLSLprogram();
		~GLSLprogram();

		void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
		void linkShaders();
		void compileShader(const std::string& ShaderFilePath, GLuint id);

		void addAttribute(const std::string &attributeName);
		GLint getUniformLocation(const std::string &uniformName);
		void use();
		void unUse();
	private:
		int _numAttributes;

		GLuint _programID;
		GLuint _vertexShaderID, _fragmentShaderID;
		


	};

};