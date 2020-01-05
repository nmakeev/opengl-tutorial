cmake_minimum_required(VERSION 3.15)
project(opengl_tutorial)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

set(glfw3_DIR D:/tools/glfw/lib/cmake/glfw3)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(opengl_tutorial src/main.cpp)

target_link_libraries(opengl_tutorial glfw)
target_include_directories(opengl_tutorial PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(opengl_tutorial ${OPENGL_gl_LIBRARY})

add_subdirectory(glad/)
target_link_libraries(opengl_tutorial glad)