#include "GLSLprogram.h"
#include "Error.h"
#include <fstream>
#include <vector>
GLSLprogram::GLSLprogram() :_numAttributes(0),_programID(0), _vertexShaderID(0), _fragmentShaderID(0)
{

}


GLSLprogram::~GLSLprogram()
{

}


void GLSLprogram::compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath)
{
	_vertexShaderID=glCreateShader(GL_VERTEX_SHADER);
	if (_vertexShaderID==0)
	{
		fatalerror("Vertex shader failed to create");
	}

	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragmentShaderID == 0)
	{
		fatalerror("Frag shader failed to create");
	}

	compileShader(vertexShaderFilePath,_vertexShaderID);
	compileShader(fragmentShaderFilePath,_fragmentShaderID);






};

void GLSLprogram::linkShaders()
{
	_programID = glCreateProgram();

	

	//Attach our shaders to our program
	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);

	//Link our program
	glLinkProgram(_programID);

	//Note the different functions here: glGetProgram* instead of glGetShader*.
	GLint isLinked = 0;
	glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

		//The maxLength includes the NULL character
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &infoLog[0]);

		//We don't need the program anymore.
		glDeleteProgram(_programID);
		//Don't leak shaders either.
		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);

		//Use the infoLog as you see fit.

		std::printf("%s\n",&(infoLog[0]));
		fatalerror("Linking Error");
		//In this simple program, we'll just leave
		return;
	}

	//Always detach shaders after a successful link.
	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);
	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);

};

void  GLSLprogram::addAttribute(const std::string &attributeName)
{
	
	glBindAttribLocation(_programID,_numAttributes++,attributeName.c_str());
};


void  GLSLprogram::compileShader(const std::string& ShaderFilePath, GLuint id)
{

	std::ifstream vertexFile(ShaderFilePath);

	if (vertexFile.fail())
	{
		fatalerror("Fail to open vertex Shader" + ShaderFilePath);
	}

	std::string fileContent;
	std::string line;

	while (std::getline(vertexFile, line))
	{
		fileContent += line + '\n';

	}

	vertexFile.close();
	const char* contentPtr = fileContent.c_str();
	glShaderSource(id, 1, &contentPtr, nullptr);

	glCompileShader(id);

	GLint isCompiled = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &isCompiled);
	if (isCompiled == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);

		// Provide the infolog in whatever manor you deem best.
		// Exit with failure.
		glDeleteShader(id); // Don't leak the shader.

		std::printf("%s\n", &(errorLog[0]));
		fatalerror(" shader failed to compile"+ShaderFilePath);
		return;
	}



};

void GLSLprogram::use()
{
	glUseProgram(_programID);

	for (int i = 0; i < _numAttributes;i++)
	{
		glEnableVertexAttribArray(i);
	}
};
void GLSLprogram::unUse()
{
	glUseProgram(0);
	for (int i = 0; i < _numAttributes; i++)
	{
		glDisableVertexAttribArray(0);
	}
};
