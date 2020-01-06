//
// Created by nsmak on 05.01.2020.
//

#include <glad/glad.h>
#include "loader.h"
#include <iostream>

//TODO: no need to use vector here?
RawModel Loader::loadToVAO(std::vector<float> positions, std::vector<int> indicies) {
  GLuint vertexCount = indicies.size();
  GLuint vaoID = createVAO();
  bindIndiciesBuffer(move(indicies));
  storeDataInAttributeList(0, move(positions));
  unbindVAO();

  return RawModel(vaoID, vertexCount);
}

unsigned int Loader::createVAO() {
  GLuint vaoID;
  glGenVertexArrays(1, &vaoID); //1 is the count of generated arrays
  m_vaos.push_back(vaoID);
  glBindVertexArray(vaoID);
  return vaoID;
}

void Loader::storeDataInAttributeList(int attributeNumber, std::vector<float> data) {
  unsigned int vboID;
  glGenBuffers(1, &vboID);
  m_vbos.push_back(vboID);
  glBindBuffer(GL_ARRAY_BUFFER, vboID);
  glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), &data[0], GL_STATIC_DRAW); //https://stackoverflow.com/questions/7173494/vbos-with-stdvector
  //TODO: 1. wtf is (void*)? 2. why 3 * sizeof(float), and no 0? 3. error: attribute num is int, but function is waiting for uint
  glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
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
}

void Loader::bindIndiciesBuffer(std::vector<int> indicies) {
  GLuint vboID;
  glGenBuffers(1, &vboID);
  m_vbos.push_back(vboID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicies.size() * sizeof(int), &indicies[0], GL_STATIC_DRAW);
  //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); //TODO: causes an error! Why we don't need to unbind IBO???
}
