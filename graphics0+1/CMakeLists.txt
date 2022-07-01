cmake_minimum_required(VERSION 3.22)
project(graphics)

set(CMAKE_CXX_STANDARD 14)

add_executable(graphics cmake-build-debug/src/main.cpp cmake-build-debug/include/ifs.h cmake-build-debug/include/image.h cmake-build-debug/include/matrix.h cmake-build-debug/include/vectors.h cmake-build-debug/src/ifs.cpp cmake-build-debug/src/image.cpp cmake-build-debug/src/matrix.cpp cmake-build-debug/include/object.h cmake-build-debug/include/material.h cmake-build-debug/include/ray.h cmake-build-debug/include/hit.h cmake-build-debug/include/camera.h cmake-build-debug/src/commandlinecheck.cpp cmake-build-debug/include/scene_parser.h cmake-build-debug/src/scene_parser.cpp cmake-build-debug/include/group.h cmake-build-debug/include/sphere.h cmake-build-debug/include/orthographic_camera.h cmake-build-debug/src/orthographic_camera.cpp)

target_include_directories(graphics PUBLIC ~/CLionProjects/graphics0+1/cmake-build-debug/include)