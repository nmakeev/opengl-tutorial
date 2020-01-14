//
// Created by nsmak on 14.01.2020.
//

#include <iostream>

#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale

#include "utils.h"

/*
 * TODO:
 * 1. fix sc var name
 * 2. think about more glm way
 */
static glm::mat4 createTransformationMatrix(glm::vec3 translation, float rx, float ry, float rz, float sc) {
  using namespace glm;
  mat4 result = translate(mat4(1.0f), translation);
  result = rotate(result, radians(rx), vec3(1, 0, 0));
  result = rotate(result, radians(ry), vec3(0, 1, 0));
  result = rotate(result, radians(rz), vec3(0, 0, 1));
  result = scale(result, vec3(sc, sc, sc));
  return result;
}