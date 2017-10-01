cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS -Wall)

add_executable(HeapTest test_data_structures.t.cpp)
target_link_libraries(HeapTest gtest gtest_main heap)