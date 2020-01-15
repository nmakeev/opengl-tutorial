//
// Created by nsmak on 05.01.2020.
//

#ifndef OPENGL_TUTORIAL_RENDERER_H
#define OPENGL_TUTORIAL_RENDERER_H

#include <src/entities/entity.h>
#include <src/shaders/static_shader.h>

/*
 * TODO: screen width and height can be changed! We need to:
 * - pass new values to renderer;
 * - recalc projection matrix;
 * - and update all shaders, that a using projection matricies.
 * So we need an interface, that accept projection matrix and shader stash?
 */

class Renderer {
public:
  Renderer(float fov, float nearPlane, float farPlane, float width, float height);

  void prepare();
  void render(Entity& entity, StaticShader& shader);

  void loadProjectionMatrixTo(StaticShader& shader) const; //TODO: think about this!
private:
  const float FOV;
  const float NEAR_PLANE;
  const float FAR_PLANE;

  float m_width;
  float m_height;

  glm::mat4 m_projectionMatrix;

  void createProjectionMatrix();
};

#endif //OPENGL_TUTORIAL_RENDERER_H
