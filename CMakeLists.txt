cmake_minimum_required(VERSION 3.22)
project(openray)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(openray
        src/main.cpp
        )
