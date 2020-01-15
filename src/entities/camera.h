//
// Created by nsmak on 15.01.2020.
//

#ifndef OPENGL_TUTORIAL_CAMERA_H
#define OPENGL_TUTORIAL_CAMERA_H

#include <glm/vec3.hpp>

class Camera {

public:
  Camera();

  glm::vec3 GetPosition() const;
  float GetPitch() const;
  float GetYaw() const;
  float GetRoll() const;

  void Move(int key);

private:
  glm::vec3 m_position;
  float m_pitch;
  float m_yaw;
  float m_roll;
};

#endif //OPENGL_TUTORIAL_CAMERA_H
