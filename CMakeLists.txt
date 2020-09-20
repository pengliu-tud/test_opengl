cmake_minimum_required(VERSION 3.17)
project(test_opengl)
find_package( OpenCV 4 REQUIRED )
find_package(GLEW REQUIRED)
#find_package(GLFW REQUIRED)
##--- Find GLUT
#find_package(GLUT REQUIRED)
#include_directories(${GLUT_INCLUDE_DIRS})
#link_directories(${GLUT_LIBRARY_DIRS})
#add_definitions(${GLUT_DEFINITIONS})
#if(NOT GLUT_FOUND)
#    message(ERROR " GLUT not found!")
#endif(NOT GLUT_FOUND)
#
#
##--- Find OpenGL
#find_package(OpenGL REQUIRED)
#include_directories(${OpenGL_INCLUDE_DIRS})
#link_directories(${OpenGL_LIBRARY_DIRS})
#add_definitions(${OpenGL_DEFINITIONS})
#if(NOT OPENGL_FOUND)
#    message(ERROR " OPENGL not found!")
#endif(NOT OPENGL_FOUND)

set(OpenGlLinkers -lglut -lGLU -lGL -lGLEW -lglfw)
#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_executable(show_opencv_images_in_opengl show_opencv_images_in_opengl.cpp)
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries(show_opencv_images_in_opengl ${OpenCV_LIBS} ${OpenGlLinkers})
#
#add_executable(main main.cpp)
#include_directories( ${OpenCV_INCLUDE_DIRS} )
#target_link_libraries(main ${OpenCV_LIBS})

add_executable(test01 test01.cpp)
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries(test01 ${OpenCV_LIBS} ${OpenGlLinkers})

add_executable(test02 test02.cpp)
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries(test02 ${OpenCV_LIBS} ${OpenGlLinkers})