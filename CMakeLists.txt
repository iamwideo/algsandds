cmake_minimum_required(VERSION 2.8.11)

project(algs_and_data)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS -Wall)

enable_testing()

add_subdirectory(lib/gtest-1.6.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(datastructures)
add_subdirectory(sorting)

add_test(NAME data_structures_tests COMMAND HeapTest)
add_test(NAME sorting_tests COMMAND SortingTests)
