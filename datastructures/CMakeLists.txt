cmake_minimum_required(VERSION 2.8.11)

project(data_structures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS -Wall)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)
enable_testing()

