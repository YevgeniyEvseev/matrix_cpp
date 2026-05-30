cmake_minimum_required(VERSION 3.28)

project(matrix)

add_subdirectory(src)

add_executable(g_test src/test.cpp)

target_link_libraries(g_test matrix_l gtest gmock pthread)

