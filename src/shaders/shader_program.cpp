//
// Created by nsmak on 05.01.2020.
//

#include <fstream>
#include <sstream>
#include <iostream>

#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>

#include "shader_program.h"

GLuint loadShader(std::string path, GLenum type) {
  GLuint shaderID = glCreateShader(type);

  std::string code;
  try {
    std::ifstream file(path);
    if (!file.is_open()) {
      std::cerr << "SHADER LOAD ERROR:\nFile not loaded at path = " << path << std::endl;
    }

    std::stringstream ss;
    ss << file.rdbuf();
    file.close();
    code = ss.str();
  } catch (std::exception& e) {
    std::cerr << "SHADER LOAD ERROR:\n" << e.what() << std::endl;
  }

  const GLchar* shaderCode = code.c_str();

  glShaderSource(shaderID, 1, &shaderCode, NULL);
  glCompileShader(shaderID);

  //TODO: check compile errors

  return shaderID;
}

void checkShaderError(int shaderId) {
  int success;
  glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
  if (!success) {
    char infoLog[512];
    glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
    std::cerr << "ERROR VERTEX SHADER COMPILATION FAILED" << '\n';
    std::cerr << infoLog << std::endl;
  }
}

ShaderProgram::ShaderProgram(std::string vertexFile, std::string fragmentFile) : m_vertexFile(move(vertexFile)), m_fragmentFile(move(fragmentFile)) {
}

void ShaderProgram::Init() {
  m_vertexShaderId = loadShader(move(m_vertexFile), GL_VERTEX_SHADER);
  m_fragmentShaderId = loadShader(move(m_fragmentFile), GL_FRAGMENT_SHADER);
  m_programId = glCreateProgram();
  glAttachShader(m_programId, m_vertexShaderId);
  glAttachShader(m_programId, m_fragmentShaderId);
  this->bindAttributes();
  glLinkProgram(m_programId);
  glValidateProgram(m_programId);
  this->getAllUniformLocations();

  checkShaderError(m_vertexShaderId);
  checkShaderError(m_fragmentShaderId);

  /*
   * Consideration: we have a flag: status.
   * checkShaderError puts there value 0 if there is no mistakes, otherwise - 1;
   * Then, after loading we can check this flag and shut down program gracefully with error message box
   */
}

void ShaderProgram::start() const {
  glUseProgram(m_programId);
}

void ShaderProgram::stop() const {
  glUseProgram(0);
}

//TODO: name make r-value?
void ShaderProgram::bindAttribute(int attribute, std::string name) const {
  glBindAttribLocation(m_programId, attribute, name.c_str());
}

ShaderProgram::~ShaderProgram() {
  std::cerr << "Shader program clean up" << std::endl;
  stop();
  glDetachShader(m_programId, m_vertexShaderId);
  glDetachShader(m_programId, m_fragmentShaderId);
  glDeleteShader(m_vertexShaderId);
  glDeleteShader(m_fragmentShaderId);
  glDeleteProgram(m_programId);
}

GLuint ShaderProgram::getUniformLocation(const std::string &uniformName) const {
  return glGetUniformLocation(m_programId, uniformName.c_str());
}

void ShaderProgram::loadFloat(GLint location, GLfloat value) const {
  glUniform1f(location, value);
}

void ShaderProgram::loadVector3(GLint location, glm::vec3 value) const {
  glUniform3f(location, value.x, value.y, value.z);
}

void ShaderProgram::loadBool(GLint location, bool value) const {
  glUniform1f(location, value ? 1 : 0);
}

void ShaderProgram::loadMatrix(GLint location, glm::mat4 matrix) const {
  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}


