#cmake version
cmake_minimum_required(VERSION 3.0)

#project name
Project(Lab_3)

#include
include_directories(include libs src tests)

#target
add_executable(Lab_3 test/Lab_3.cpp src/Matrix.cpp)