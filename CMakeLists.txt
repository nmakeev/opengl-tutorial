cmake_minimum_required(VERSION 3.15)
project(opengl_tutorial)

set(CMAKE_CXX_STANDARD 17)

IF (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")
    set(glfw3_DIR D:/tools/glfw/lib/cmake/glfw3)
ENDIF()

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(opengl_tutorial src/main.cpp src/models/raw_model.cpp src/models/raw_model.h src/render/loader.cpp src/render/loader.h src/render/renderer.cpp src/render/renderer.h src/shaders/shader_program.cpp src/shaders/shader_program.h src/shaders/static_shader.cpp src/shaders/static_shader.h src/stb_image.cpp src/textures/model_texture.cpp src/textures/model_texture.h src/models/textured_model.cpp src/models/textured_model.h src/utils.cpp src/utils.h src/entities/entity.cpp src/entities/entity.h src/entities/camera.cpp src/entities/camera.h)

target_link_libraries(opengl_tutorial glfw)
target_include_directories(opengl_tutorial PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(opengl_tutorial ${OPENGL_gl_LIBRARY})

add_subdirectory(glad/)
target_link_libraries(opengl_tutorial glad)

add_subdirectory(glm/)
target_link_libraries(opengl_tutorial glm)

#copy shaders to target location
add_custom_command(TARGET opengl_tutorial
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders/ $<TARGET_FILE_DIR:opengl_tutorial>/shaders/)

#copy resources to target location
add_custom_command(TARGET opengl_tutorial
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:opengl_tutorial>/resources/)