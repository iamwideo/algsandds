cmake_minimum_required(VERSION 2.8.11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS -Wall)

add_executable(SortingTests insertion_sort.t.cpp merge_sort.t.cpp)

target_link_libraries(SortingTests gtest gtest_main timer)