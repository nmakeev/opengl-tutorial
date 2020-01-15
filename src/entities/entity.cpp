//
// Created by nsmak on 15.01.2020.
//

#include "entity.h"

using namespace std;

//TODO: wtf is trivially-copyable type???

Entity::Entity(TexturedModel model, glm::vec3 position, glm::vec3 rotation, float scale)
  : m_model(std::move(model)), m_position(position), m_rotation(rotation), m_scale(scale)  {

}

const TexturedModel& Entity::GetModel() const {
  return m_model;
}

glm::vec3 Entity::GetPosition() const {
  return m_position;
}

glm::vec3 Entity::GetRotation() const {
  return m_rotation;
}

float Entity::GetScale() const {
  return m_scale;
}

void Entity::increasePosition(float dx, float dy, float dz) {
  m_position.x += dx;
  m_position.y += dy;
  m_position.z += dz;
}

void Entity::increaseRotation(float dx, float dy, float dz) {
  m_rotation.x += dx;
  m_rotation.y += dy;
  m_rotation.z += dz;
}


