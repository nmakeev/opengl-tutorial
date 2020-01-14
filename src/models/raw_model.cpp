//
// Created by nsmak on 05.01.2020.
//

#include "raw_model.h"

GLuint RawModel::getVaoID() const {
  return m_vaoID;
}

GLsizei RawModel::getVertexCount() const {
  return m_vertexCount;
}