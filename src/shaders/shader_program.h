//
// Created by nsmak on 05.01.2020.
//

#ifndef OPENGL_TUTORIAL_SHADER_PROGRAM_H
#define OPENGL_TUTORIAL_SHADER_PROGRAM_H

#include <string>

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

class ShaderProgram {

public:
  ShaderProgram(std::string vertexFile, std::string fragmentFile);
  void Init();

  ~ShaderProgram();

  void start() const;
  void stop() const;

protected:
  virtual void bindAttributes() const = 0;
  virtual void getAllUniformLocations() = 0;

  void bindAttribute(int attribute, std::string name) const;
  GLuint getUniformLocation(const std::string& uniformName) const;
  void loadFloat(GLint location, GLfloat value) const;
  void loadVector3(GLint location, glm::vec3 value) const;
  void loadBool(GLint location, bool value) const;
  void loadMatrix(GLint location, glm::mat4 matrix) const;

private:
  std::string m_vertexFile;
  std::string m_fragmentFile;

  GLuint m_programId;
  GLuint m_vertexShaderId;
  GLuint m_fragmentShaderId;
};

GLuint loadShader(std::string path, GLenum type);

#endif //OPENGL_TUTORIAL_SHADER_PROGRAM_H
