//
// Created by nsmak on 06.01.2020.
//

#ifndef OPENGL_TUTORIAL_STATIC_SHADER_H
#define OPENGL_TUTORIAL_STATIC_SHADER_H

#include <string>
#include "shader_program.h"

const std::string VERTEX_FILE = "shaders/vertexShader.glsl";
const std::string FRAGMENT_FILE = "shaders/fragmentShader.glsl";

class StaticShader : public ShaderProgram {
public:
  StaticShader();

protected:
  void bindAttributes() override;
};


#endif //OPENGL_TUTORIAL_STATIC_SHADER_H
