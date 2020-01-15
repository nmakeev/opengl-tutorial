//
// Created by nsmak on 15.01.2020.
//

#include <GLFW/glfw3.h>
#include "camera.h"

Camera::Camera() : m_position(glm::vec3(0, 0, 0)), m_pitch(.0f), m_yaw(.0f), m_roll(.0f) {
}

float Camera::GetPitch() const {
  return m_pitch;
}

float Camera::GetYaw() const {
  return m_yaw;
}

float Camera::GetRoll() const {
  return m_roll;
}

const float delta = .02f;

//TODO: terrible!!!
void Camera::Move(int key) {
  if (key == GLFW_KEY_W) {
    m_position.z -= delta;
    return;
  }

  if (key == GLFW_KEY_A) {
    m_position.x -= delta;
    return;
  }

  if (key == GLFW_KEY_S) {
    m_position.z += delta;
    return;
  }

  if (key == GLFW_KEY_D) {
    m_position.x += delta;
    return;
  }
}

glm::vec3 Camera::GetPosition() const {
  return m_position;
}
