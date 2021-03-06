//
// Created by nsmak on 06.01.2020.
//

#include "static_shader.h"

StaticShader::StaticShader() : ShaderProgram(VERTEX_FILE, FRAGMENT_FILE) {
}

void StaticShader::bindAttributes() const {
  bindAttribute(0, "position");
  bindAttribute(1, "textureCoords");
}

void StaticShader::getAllUniformLocations() {
  m_locationTransformationMatrix = getUniformLocation("transformationMatrix");
  m_locationProjectionMatrix = getUniformLocation("projectionMatrix");
  m_locationViewMatrix = getUniformLocation("viewMatrix");
}

void StaticShader::loadTransformationMatrix(glm::mat4 matrix) {
  loadMatrix(m_locationTransformationMatrix, matrix);
}

void StaticShader::loadProjectionMatrix(glm::mat4 matrix) {
  loadMatrix(m_locationProjectionMatrix, matrix);
}

void StaticShader::loadViewMatrix(glm::mat4 matrix) {
  loadMatrix(m_locationViewMatrix, matrix);
}
