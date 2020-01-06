#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <Windows.h>
#include "loader.h"
#include "renderer.h"
#include "static_shader.h"

#include <vector>

void processInput(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  if (!glfwInit())
    return -1;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  //TODO: settings there?
  const int WINDOW_WIDTH = 800;
  const int WINDOW_HEIGHT = 600;

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
  Renderer renderer;

  std::vector<float> verticies = {
       -0.5f, 0.5f, 0.0f,
       -0.5f, -0.5f, 0.0f,
       0.5f, -0.5f, 0.0f,

       0.5f, -0.5f, 0.0f,
       0.5f, 0.5f, 0.0f,
       -0.5f, 0.5f, 0.0f,
  };

  RawModel model = loader.loadToVAO(move(verticies));

  StaticShader shader;

  while (!glfwWindowShouldClose(window))
  {
    processInput(window);

    renderer.prepare();
    shader.start();
    renderer.render(model);
    shader.stop();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}