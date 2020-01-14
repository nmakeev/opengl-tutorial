//
// Created by nsmak on 05.01.2020.
//

#include "raw_model.h"

GLuint RawModel::getVaoId() const {
  return m_vaoId;
}

GLsizei RawModel::getVertexCount() const {
  return m_vertexCount;
}