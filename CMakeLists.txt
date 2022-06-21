cmake_minimum_required(VERSION 3.22)
project(openray)


set(CMAKE_CXX_STANDARD 20)

SET(RENDER
        src/render/render.cpp
        src/render/render.h)
SET(SCENE
        src/scene/scene.cpp
        src/scene/scene.h)
SET(STRUCTURES
        src/structures/segment.cpp
        src/structures/segment.h
        src/structures/primitive.cpp
        src/structures/primitive.h)

include_directories(src)

add_executable(openray
        src/main.cpp
        ${RENDER}
        ${SCENE}
        ${STRUCTURES}
        )
