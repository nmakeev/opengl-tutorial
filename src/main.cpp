#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#include <Windows.h>
#endif
#include "render/loader.h"
#include "render/renderer.h"
#include "shaders/static_shader.h"
#include "textures/model_texture.h"
#include "models/textured_model.h"
#include "utils.h"

#include <vector>
#include <src/entities/camera.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

Renderer renderer {
        70, .1f, 1000.f, WINDOW_WIDTH, WINDOW_HEIGHT //TODO: think about width, height!!!!!!!
};

Camera camera;

void processInput(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    camera.Move(GLFW_KEY_W);

  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    camera.Move(GLFW_KEY_A);

  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    camera.Move(GLFW_KEY_S);

  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    camera.Move(GLFW_KEY_D);
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
  renderer.updateScreenSize(width, height);
}

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
#else
int main()
#endif
{
  if (!glfwInit())
    return -1;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#if __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  //TODO: settings there?

  //window part
  GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL Tutorial Project", NULL, NULL);
  if (!window)
  {
    std::cout << "Failed to created GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  //glad initialization
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    glfwTerminate();
    return -1;
  }

  //vieport
  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

  Loader loader;

  std::vector<float> verticies = {
       -0.5f, 0.5f, 0.0f,   //v0
       -0.5f, -0.5f, 0.0f,  //v1
       0.5f, -0.5f, 0.0f,   //v2
       0.5f, 0.5f, 0.0f,    //v3
  };

  std::vector<int> indicies = {
          0, 1, 3,
          3, 1, 2
  };

  std::vector<float> textureCoords = {
          0.f, 0.f,
          0.f, 1.f,
          1.f, 1.f,
          1.f, 0.f
  };

  RawModel model = loader.loadToVAO(move(verticies), move(textureCoords), move(indicies));
  ModelTexture texture {loader.loadTexture("resources/stones.jpg", false)};
  TexturedModel texturedModel {
    model, texture
  };

  StaticShader shader;
  shader.Init();


  Entity entity {
    std::move(texturedModel), glm::vec3(0, 0, -2), glm::vec3(0, 0, 0), 1
  };

  while (!glfwWindowShouldClose(window))
  {
    processInput(window);

    renderer.loadProjectionMatrixTo(shader); //TODO: no need to pass proj matrix each time!!!
    renderer.prepare();
    shader.start();
    shader.loadViewMatrix(createViewMatrix(camera));
    renderer.render(entity, shader);
    shader.stop();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}

