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

  ~ShaderProgram();

  void start() const;
  void stop() const;

protected:
  virtual void bindAttributes() const;
  void bindAttribute(int attribute, std::string name) const;

private:
  GLuint m_programID;
  GLuint m_vertexShaderID;
  GLuint m_fragmentShaderID;
};

GLuint loadShader(std::string path, GLenum type);

#endif //OPENGL_TUTORIAL_SHADER_PROGRAM_H
