//
// Created by nsmak on 07.01.2020.
//

#include "textured_model.h"

#include <utility>

using namespace std;

TexturedModel::TexturedModel(RawModel model, ModelTexture texture) : m_model(move(model)), m_texture(move(texture)) {
}

const RawModel &TexturedModel::getModel() const {
  return m_model;
}

const ModelTexture &TexturedModel::getTexture() const {
  return m_texture;
}