//
// Created by nsmak on 05.01.2020.
//

#ifndef OPENGL_TUTORIAL_RENDERER_H
#define OPENGL_TUTORIAL_RENDERER_H

#include "raw_model.h"
#include "textured_model.h"

class Renderer {
public:
  void prepare();
  void render(RawModel& model);
  void render(TexturedModel& textured_model);
};


#endif //OPENGL_TUTORIAL_RENDERER_H
