//
// Created by nsmak on 14.01.2020.
//

#ifndef OPENGL_TUTORIAL_UTILS_H
#define OPENGL_TUTORIAL_UTILS_H

#include <glm/mat4x4.hpp>
#include <src/entities/camera.h>

glm::mat4 createTransformationMatrix(glm::vec3 translation, glm::vec3 rotation, float scale);

glm::mat4 createViewMatrix(const Camera& camera); //TODO: isn't it should be Camera method?

void checkError(int pos);

#endif //OPENGL_TUTORIAL_UTILS_H
