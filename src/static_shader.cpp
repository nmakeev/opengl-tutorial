//
// Created by nsmak on 06.01.2020.
//

#include "static_shader.h"

StaticShader::StaticShader() : ShaderProgram(VERTEX_FILE, FRAGMENT_FILE) {
}

void StaticShader::bindAttributes() {
  bindAttribute(0, "position");
}
