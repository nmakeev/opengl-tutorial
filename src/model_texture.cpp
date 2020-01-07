//
// Created by nsmak on 07.01.2020.
//

#include "model_texture.h"

ModelTexture::ModelTexture(GLuint id) {
  this->m_id = id;
}

GLuint ModelTexture::getID() const {
  return m_id;
}
