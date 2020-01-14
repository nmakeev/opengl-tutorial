//
// Created by nsmak on 05.01.2020.
//

#include "glad/glad.h"
#include "renderer.h"
#include "../models/textured_model.h"

void Renderer::prepare() {
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(RawModel& model) {
  glBindVertexArray(model.getVaoID());
  glEnableVertexAttribArray(0); //TODO: this is not ok
  //glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
  glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);
  glDisableVertexAttribArray(0);
  glBindVertexArray(0);
}

void Renderer::render(TexturedModel& textured_model) {
  glBindVertexArray(textured_model.getModel().getVaoID());
  glEnableVertexAttribArray(0); //TODO: this is not ok
  glEnableVertexAttribArray(1);
  //glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, textured_model.getTexture().getID());
  glDrawElements(GL_TRIANGLES, textured_model.getModel().getVertexCount(), GL_UNSIGNED_INT, 0);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glBindVertexArray(0);
}