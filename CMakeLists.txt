cmake_minimum_required(VERSION 2.7)
project(project3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -Wno-unused-result")

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})

add_executable(part1 part1.cpp d.h d.cpp)
add_executable(part2 main.cpp vector.h vector.cpp colorfig.h colorfig.cpp group.h group.cpp random.cpp random.h)


target_link_libraries(part2 ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)
