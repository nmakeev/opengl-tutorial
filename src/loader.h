//
// Created by nsmak on 05.01.2020.
//

#ifndef OPENGL_TUTORIAL_LOADER_H
#define OPENGL_TUTORIAL_LOADER_H

#include <vector>
#include <string>

#include "raw_model.h"

class Loader {
public:
  RawModel loadToVAO(std::vector<float> positions, std::vector<int> indicies);
  RawModel loadToVAO(std::vector<float> positions, std::vector<float> textureCoords, std::vector<int> indicies);
  GLuint loadTexture(std::string fileName, bool has_alpha);
  ~Loader();
private:
  unsigned int createVAO();
  void storeDataInAttributeList(int attributeNumber, int coordinateSize, std::vector<float> data);
  void unbindVAO() const;
  void bindIndiciesBuffer(std::vector<int> indicies);

  std::vector<GLuint> m_vaos;
  std::vector<GLuint> m_vbos;
  std::vector<GLuint> m_textures;
};


#endif //OPENGL_TUTORIAL_LOADER_H
