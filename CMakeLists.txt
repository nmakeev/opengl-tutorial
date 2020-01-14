cmake_minimum_required(VERSION 3.15)
project(opengl_tutorial)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")

set(glfw3_DIR D:/tools/glfw/lib/cmake/glfw3)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(opengl_tutorial src/main.cpp src/raw_model.cpp src/raw_model.h src/loader.cpp src/loader.h src/renderer.cpp src/renderer.h src/shader_program.cpp src/shader_program.h src/static_shader.cpp src/static_shader.h src/stb_image.cpp src/model_texture.cpp src/model_texture.h src/textured_model.cpp src/textured_model.h)

target_link_libraries(opengl_tutorial glfw)
target_include_directories(opengl_tutorial PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(opengl_tutorial ${OPENGL_gl_LIBRARY})

add_subdirectory(glad/)
target_link_libraries(opengl_tutorial glad)

#copy shaders to target location
add_custom_command(TARGET opengl_tutorial
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders/ $<TARGET_FILE_DIR:opengl_tutorial>/shaders/)

#copy resources to target location
add_custom_command(TARGET opengl_tutorial
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:opengl_tutorial>/resources/)