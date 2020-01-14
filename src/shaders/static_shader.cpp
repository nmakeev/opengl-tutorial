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
}

void StaticShader::loadTransformationMatrix(glm::mat4 matrix) {
  loadMatrix(m_locationTransformationMatrix, matrix);
}
