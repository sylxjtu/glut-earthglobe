cmake_minimum_required(VERSION 3.6)
project(glut)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp TextureImage.cpp TextureImage.h)
add_executable(glut ${SOURCE_FILES})
target_link_libraries(glut opengl32)
target_link_libraries(glut glu32)
target_link_libraries(glut glew32)
target_link_libraries(glut freeglut)

configure_file(earth.bmp earth.bmp COPYONLY)