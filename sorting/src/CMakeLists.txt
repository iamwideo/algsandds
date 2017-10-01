cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS -Wall)

include_directories(.)
add_library(timer timer.cpp)

