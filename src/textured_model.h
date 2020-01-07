//
// Created by nsmak on 07.01.2020.
//

#ifndef OPENGL_TUTORIAL_TEXTURED_MODEL_H
#define OPENGL_TUTORIAL_TEXTURED_MODEL_H

#include "raw_model.h"
#include "model_texture.h"

class TexturedModel {
public:
  TexturedModel(RawModel model, ModelTexture texture);
  const RawModel& getModel() const;
  const ModelTexture& getTexture() const;
private:
  RawModel m_model;
  ModelTexture m_texture;
};


#endif //OPENGL_TUTORIAL_TEXTURED_MODEL_H
