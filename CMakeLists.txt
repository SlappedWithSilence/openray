cmake_minimum_required(VERSION 3.3)
project(openray)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)