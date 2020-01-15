//
// Created by nsmak on 15.01.2020.
//

#ifndef OPENGL_TUTORIAL_ENTITY_H
#define OPENGL_TUTORIAL_ENTITY_H

#include <src/models/textured_model.h> //WTF???
#include <glm/glm.hpp>

class Entity {
public:
  Entity(TexturedModel model, glm::vec3 position, glm::vec3 rotation, float scale);

  const TexturedModel& GetModel() const;
  glm::vec3 GetPosition() const;
  glm::vec3 GetRotation() const;
  float GetScale() const;

  void increasePosition(float dx, float dy, float dz); //TODO: fix me
  void increaseRotation(float dx, float dy, float dz); //TODO: fix me
private:
  TexturedModel m_model;
  glm::vec3 m_position;
  glm::vec3 m_rotation; //TODO: quaternions
  float m_scale;
};


#endif //OPENGL_TUTORIAL_ENTITY_H
