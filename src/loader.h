//
// Created by nsmak on 05.01.2020.
//

#ifndef OPENGL_TUTORIAL_LOADER_H
#define OPENGL_TUTORIAL_LOADER_H

#include <vector>
#include "raw_model.h"

class Loader {
public:
  RawModel loadToVAO(std::vector<float> positions);
  ~Loader();
private:
  unsigned int createVAO();
  void storeDataInAttributeList(int attributeNumber, std::vector<float> data);
  void unbindVAO() const;

  std::vector<GLuint> m_vaos;
  std::vector<GLuint> m_vbos;
};


#endif //OPENGL_TUTORIAL_LOADER_H
