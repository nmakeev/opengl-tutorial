//
// Created by nsmak on 05.01.2020.
//

#include <fstream>
#include <sstream>
#include "glad/glad.h"
#include <iostream>

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

ShaderProgram::ShaderProgram(std::string vertexFile, std::string fragmentFile) {
  m_vertexShaderId = loadShader(move(vertexFile), GL_VERTEX_SHADER);
  m_fragmentShaderId = loadShader(move(fragmentFile), GL_FRAGMENT_SHADER);
  m_programId = glCreateProgram();
  glAttachShader(m_programId, m_vertexShaderId);
  glAttachShader(m_programId, m_fragmentShaderId);
  bindAttributes();
  glLinkProgram(m_programId);
  glValidateProgram(m_programId);

  checkShaderError(m_vertexShaderId);
  checkShaderError(m_fragmentShaderId);

  /*
   * Consideration: we have a flag: status.
   * checkShaderError puts there value 0 if there is no mistakes, otherwise - 1;
   * Then, after loading we can check this flag and shut down program gracefully with error message box
   */
}

void ShaderProgram::bindAttributes() const {
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

