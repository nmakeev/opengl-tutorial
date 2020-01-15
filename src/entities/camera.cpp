//
// Created by nsmak on 15.01.2020.
//

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
