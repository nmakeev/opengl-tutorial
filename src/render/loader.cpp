//
// Created by nsmak on 05.01.2020.
//

#include <glad/glad.h>
#include "loader.h"
#include "../stb_image.h"
#include <iostream>

//TODO: no need to use vector here?
RawModel Loader::loadToVAO(std::vector<float> positions, std::vector<int> indicies) {
  GLuint vertexCount = indicies.size();
  GLuint vaoID = createVAO();
  bindIndiciesBuffer(move(indicies));
  storeDataInAttributeList(0, 3, move(positions));
  unbindVAO();

  return RawModel(vaoID, vertexCount);
}

RawModel Loader::loadToVAO(std::vector<float> positions, std::vector<float> textureCoords, std::vector<int> indicies) {
  GLuint vertexCount = indicies.size();
  GLuint vaoID = createVAO();
  bindIndiciesBuffer(move(indicies));
  storeDataInAttributeList(0, 3, move(positions));
  storeDataInAttributeList(1, 2, move(textureCoords));
  unbindVAO();

  return RawModel(vaoID, vertexCount);
}

GLuint Loader::createVAO() {
  GLuint vaoID;
  glGenVertexArrays(1, &vaoID); //1 is the count of generated arrays
  m_vaos.push_back(vaoID);
  glBindVertexArray(vaoID);
  return vaoID;
}

void Loader::storeDataInAttributeList(int attributeNumber, int coordinateSize, std::vector<float> data) {
  unsigned int vboID;
  glGenBuffers(1, &vboID);
  m_vbos.push_back(vboID);
  glBindBuffer(GL_ARRAY_BUFFER, vboID);
  glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW); //https://stackoverflow.com/questions/7173494/vbos-with-stdvector
  //TODO: 1. wtf is (void*)? 2. why 3 * sizeof(float), and no 0? 3. error: attribute num is int, but function is waiting for uint
  glVertexAttribPointer(attributeNumber, coordinateSize, GL_FLOAT, GL_FALSE, coordinateSize * sizeof(float), (void*)0);
  //glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Loader::unbindVAO() const {
  glBindVertexArray(0);
}

Loader::~Loader() {
  std::cerr << "Loader clean up" << std::endl;

  for (auto vaoID : m_vaos) {
    glDeleteVertexArrays(1, &vaoID);
  }

  for (auto vboID : m_vbos) {
    glDeleteBuffers(1, &vboID);
  }

  //TODO: I think, I can pass something like that: glDeleteTextures(m_textures.size(), &m_textures[0]) ???
  for (auto textureID : m_textures) {
    glDeleteTextures(1, &textureID);
  }
}

void Loader::bindIndiciesBuffer(std::vector<int> indicies) {
  GLuint vboID;
  glGenBuffers(1, &vboID);
  m_vbos.push_back(vboID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(int), &indicies[0], GL_STATIC_DRAW);
  //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); //TODO: causes an error! Why we don't need to unbind IBO???
}

GLuint Loader::loadTexture(std::string fileName, bool has_alpha) {
  GLuint textureId;
  glGenTextures(1, &textureId);
  m_textures.push_back(textureId);
  glBindTexture(GL_TEXTURE_2D, textureId);
  //wrapping parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  //filtering parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  int width, height, nrChannels;
  unsigned char *data = stbi_load(fileName.c_str(), &width, &height, &nrChannels, 0);
  if (data)
  {
    if (has_alpha)
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    else
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else
  {
    std::cerr << "Failed to load texture with name = " << fileName << std::endl;
  }
  stbi_image_free(data);

  return textureId;
}
