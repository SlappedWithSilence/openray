

SET(RENDER
        render/render.cpp
        render/render.h)
SET(SCENE
        scene/scene.cpp
        scene/scene.h)
SET(STRUCTURES
        structures/segment.cpp
        structures/segment.h
        structures/primitive.cpp
        structures/primitive.h
        )

set(core_SRCS
        ${RENDER}
        ${SCENE}
        ${STRUCTURES}
        )

add_library(core ${core_SRCS})
add_executable(exe main.cpp)
target_link_libraries(exe core)