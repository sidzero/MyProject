#pragma once
#include <glew\glew.h>
#include <string>
class GLSLprogram
{
public:
	GLSLprogram();
	~GLSLprogram();

	void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
	void linkShaders();


	void addAttribute(const std::string &attributeName);
	GLint getUniformLocation(const std::string &uniformName );
	void use();
	void unUse();
private:
	int _numAttributes;

	GLuint _programID;
	GLuint _vertexShaderID, _fragmentShaderID;
	void compileShader(const std::string& ShaderFilePath,GLuint id);


};

