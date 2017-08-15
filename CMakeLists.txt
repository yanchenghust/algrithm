cmake_minimum_required(VERSION 3.8)
project(C)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp hash.h binaryTree.h dp/matrix1.h)
add_executable(C ${SOURCE_FILES})