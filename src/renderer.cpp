//
// Created by nsmak on 05.01.2020.
//

#include "glad/glad.h"
#include "renderer.h"

void Renderer::prepare() {
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(RawModel& model) {
  glBindVertexArray(model.getVaoID());
  glEnableVertexAttribArray(0); //TODO: this is not ok
  glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
  glDisableVertexAttribArray(0);
  glBindVertexArray(0);
}
