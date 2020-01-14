//
// Created by nsmak on 05.01.2020.
//

#ifndef OPENGL_TUTORIAL_RENDERER_H
#define OPENGL_TUTORIAL_RENDERER_H

#include "../models/raw_model.h"
#include "../models/textured_model.h"

class Renderer {
public:
  void prepare();
  void render(RawModel& model);
  void render(TexturedModel& textured_model);
};


#endif //OPENGL_TUTORIAL_RENDERER_H
