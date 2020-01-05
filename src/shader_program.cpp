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
    std::cerr << "SHADER LOAD ERROR:" << '\n' << e.what() << std::endl;
  }

  const GLchar* shaderCode = code.c_str();

  glShaderSource(shaderID, 1, &shaderCode, NULL);
  glCompileShader(shaderID);

  //TODO: check compile errors

  return shaderID;
}

ShaderProgram::ShaderProgram(std::string vertexFile, std::string fragmentFile) {
  m_vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
  m_fragmentShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
  m_programID = glCreateProgram();
  glAttachShader(m_programID, m_vertexShaderID);
  glAttachShader(m_programID, m_fragmentShaderID);
  glLinkProgram(m_programID);
  glValidateProgram(m_programID);
  bindAttributes();

  int success;
  char infoLog[512];
  glGetShaderiv(m_vertexShaderID, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(m_vertexShaderID, 512, NULL, infoLog);
    std::cerr << "ERROR VERTEX SHADER COMIPLATION FAILED" << '\n';
    std::cerr << infoLog << std::endl;
  }

  glGetShaderiv(m_fragmentShaderID, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(m_fragmentShaderID, 512, NULL, infoLog);
    std::cerr << "ERROR VERTEX SHADER COMIPLATION FAILED" << '\n';
    std::cerr << infoLog << std::endl;
  }
}

void ShaderProgram::bindAttributes() {

}

void ShaderProgram::start() {
  glUseProgram(m_programID);
}

void ShaderProgram::stop() {
  glUseProgram(0);
}

void ShaderProgram::cleanUp() {
  stop();
  glDetachShader(m_programID, m_vertexShaderID);
  glDetachShader(m_programID, m_fragmentShaderID);
  glDeleteShader(m_vertexShaderID);
  glDeleteShader(m_fragmentShaderID);
  glDeleteProgram(m_programID);
}

void ShaderProgram::bindAttribute(int attribute, std::string name) {
  glBindAttribLocation(m_programID, attribute, name.c_str());
}

