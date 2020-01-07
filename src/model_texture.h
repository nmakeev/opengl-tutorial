//
// Created by nsmak on 07.01.2020.
//

#ifndef OPENGL_TUTORIAL_MODEL_TEXTURE_H
#define OPENGL_TUTORIAL_MODEL_TEXTURE_H

#include <glad/glad.h>

class ModelTexture {
public:
  ModelTexture(GLuint id);
  GLuint getID() const;
private:
  GLuint m_id;
};


#endif //OPENGL_TUTORIAL_MODEL_TEXTURE_H
