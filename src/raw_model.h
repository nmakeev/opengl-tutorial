//
// Created by nsmak on 05.01.2020.
//

#ifndef OPENGL_TUTORIAL_RAW_MODEL_H
#define OPENGL_TUTORIAL_RAW_MODEL_H

#include "glad/glad.h"

class RawModel {
public:
  RawModel(GLuint vaoID, GLsizei vertexCount) :
    m_vaoID(vaoID), m_vertexCount(vertexCount) {
  }
  GLuint getVaoID() const;
  GLsizei getVertexCount() const;
private:
  GLuint m_vaoID;
  GLsizei m_vertexCount;
};


#endif //OPENGL_TUTORIAL_RAW_MODEL_H
