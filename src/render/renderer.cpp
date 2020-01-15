//
// Created by nsmak on 05.01.2020.
//

#include <glm/mat4x4.hpp>
#include <glad/glad.h>
#include <src/utils.h>

#include "renderer.h"

Renderer::Renderer(float fov, float nearPlane, float farPlane, float width, float height)
  : FOV(fov), NEAR_PLANE(nearPlane), FAR_PLANE(farPlane), m_width(width), m_height(height) {
  createProjectionMatrix();
}


void Renderer::prepare() {
  glEnable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
}

void Renderer::render(Entity& entity, StaticShader& shader) {
  const auto& textured_model = entity.GetModel();
  const auto& raw_model = textured_model.getModel();
  glBindVertexArray(raw_model.getVaoId());
  glEnableVertexAttribArray(0); //TODO: this is not ok
  glEnableVertexAttribArray(1);

  glm::mat4x4 transformationMatrix = createTransformationMatrix(entity.GetPosition(), entity.GetRotation(), entity.GetScale());
  shader.loadTransformationMatrix(transformationMatrix);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, textured_model.getTexture().getID());
  glDrawElements(GL_TRIANGLES, raw_model.getVertexCount(), GL_UNSIGNED_INT, 0);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glBindVertexArray(0);
}

//TODO: how to build projection matrix http://www.opengl-tutorial.org/ru/beginners-tutorials/tutorial-3-matrices/
void Renderer::createProjectionMatrix() {
  float aspectRatio = m_width / m_height;
  float yScale = (1.f / tanf(glm::radians(FOV / 2))) * aspectRatio;
  float xScale = yScale / aspectRatio;
  float frustumLength = FAR_PLANE - NEAR_PLANE;

  //m_projectionMatrix = glm::mat4{0};
  m_projectionMatrix[0][0] = xScale;
  m_projectionMatrix[1][1] = yScale;
  m_projectionMatrix[2][2] = -((FAR_PLANE + NEAR_PLANE) / frustumLength);
  m_projectionMatrix[2][3] = -1;
  m_projectionMatrix[3][2] = -((2 * NEAR_PLANE * FAR_PLANE) / frustumLength);
  m_projectionMatrix[3][3] = 0;
}

void Renderer::loadProjectionMatrixTo(StaticShader& shader) const {
  shader.start();
  shader.loadProjectionMatrix(m_projectionMatrix);
  shader.stop();
}

void Renderer::updateScreenSize(float width, float height) {
  m_width = width;
  m_height = height;

  createProjectionMatrix();
}
