//
// Created by nsmak on 14.01.2020.
//

#include <iostream>

#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glad/glad.h>

#include "utils.h"

/*
 * TODO:
 * 1. fix sc var name
 * 2. think about more glm way
 */
glm::mat4 createTransformationMatrix(glm::vec3 translation, glm::vec3 rotation, float sc) {
  using namespace glm;
  mat4 result = translate(mat4(1.0f), translation);
  result = rotate(result, radians(rotation.x), vec3(1, 0, 0));
  result = rotate(result, radians(rotation.y), vec3(0, 1, 0));
  result = rotate(result, radians(rotation.z), vec3(0, 0, 1));
  result = scale(result, vec3(sc, sc, sc));
  return result;
}

glm::mat4 createViewMatrix(const Camera& camera) {
  using namespace glm;
  mat4 result{1.f};
  result = rotate(result, radians(camera.GetPitch()), vec3(1, 0, 0));
  result = rotate(result, radians(camera.GetYaw()), vec3(0, 1, 0));
  result = translate(result, -camera.GetPosition());
  return result;
}

void checkError(int pos) {
  GLenum error = glGetError();
  if (error == 0)
    return;

  std::cerr << "OpenGL error, code = " << error << ", pos = " << pos <<  std::endl;
}