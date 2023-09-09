cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

project(leetcode)

set(LIB_NAME leetcode)
set(LIB_INCLUDE ${CMAKE_SOURCE_DIR}/include/)

add_subdirectory(src)
add_subdirectory(tests)