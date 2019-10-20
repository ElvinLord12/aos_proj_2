cmake_minimum_required(VERSION 3.14)
project(proj_1)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp RBTree.cpp RBTree.h SplayTree.cpp)
add_executable(proj_1 ${SOURCE_FILES})