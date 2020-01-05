//
// Created by nsmak on 05.01.2020.
//

#ifndef OPENGL_TUTORIAL_RAW_MODEL_H
#define OPENGL_TUTORIAL_RAW_MODEL_H


class RawModel {
public:
  RawModel(int vaoID, int vertexCount) :
    m_vaoID(vaoID), m_vertexCount(vertexCount) {
  }
  unsigned int getVaoID() const;
  int getVertexCount() const;
private:
  unsigned int m_vaoID;
  int m_vertexCount;
};


#endif //OPENGL_TUTORIAL_RAW_MODEL_H
