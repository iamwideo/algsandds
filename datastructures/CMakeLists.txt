cmake_minimum_required(VERSION 2.8.11)
project(test_sorting)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS -Wall)

add_subdirectory(lib/gtest-1.6.0)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} .)

add_library(heap heap.cpp)

add_executable(runUnitTests test_data_structures.t.cpp)
target_link_libraries(runUnitTests gtest gtest_main heap)
add_test(runUnitTests runUnitTests)
