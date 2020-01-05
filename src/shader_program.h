//
// Created by nsmak on 05.01.2020.
//

#ifndef OPENGL_TUTORIAL_SHADER_PROGRAM_H
#define OPENGL_TUTORIAL_SHADER_PROGRAM_H

#include "glad/glad.h"
#include <string>

class ShaderProgram {

public:
  ShaderProgram(std::string vertexFile, std::string fragmentFile);

  //TODO: complete forgot about const!!!!!!!
  void start();
  void stop();

  void cleanUp();

protected:
  virtual void bindAttributes();
  void bindAttribute(int attribute, std::string name);

private:
  GLuint m_programID;
  GLuint m_vertexShaderID;
  GLuint m_fragmentShaderID;
};

GLuint loadShader(std::string path, GLenum type);

#endif //OPENGL_TUTORIAL_SHADER_PROGRAM_H
