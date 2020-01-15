//
// Created by nsmak on 06.01.2020.
//

#ifndef OPENGL_TUTORIAL_STATIC_SHADER_H
#define OPENGL_TUTORIAL_STATIC_SHADER_H

#include <string>

#include <glm/mat4x4.hpp>

#include "shader_program.h"

const std::string VERTEX_FILE = "shaders/vertexShader.glsl";
const std::string FRAGMENT_FILE = "shaders/fragmentShader.glsl";

class StaticShader : public ShaderProgram {
public:
  StaticShader();
  void loadTransformationMatrix(glm::mat4 matrix);
  void loadProjectionMatrix(glm::mat4 matrix);

protected:
  void bindAttributes() const override;
  void getAllUniformLocations() override;

private:
  GLint m_locationTransformationMatrix;
  GLint m_locationProjectionMatrix;
};


#endif //OPENGL_TUTORIAL_STATIC_SHADER_H
