//
// Created by nsmak on 05.01.2020.
//

#ifndef OPENGL_TUTORIAL_RAW_MODEL_H
#define OPENGL_TUTORIAL_RAW_MODEL_H

#include "glad/glad.h"

class RawModel {
public:
  RawModel(GLuint vaoId, GLsizei vertexCount) :
          m_vaoId(vaoId), m_vertexCount(vertexCount) {
  }
  GLuint getVaoId() const;
  GLsizei getVertexCount() const;
private:
  GLuint m_vaoId;
  GLsizei m_vertexCount;
};


#endif //OPENGL_TUTORIAL_RAW_MODEL_H
