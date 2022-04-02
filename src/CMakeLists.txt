set(BINARY ${CMAKE_PROJECT_NAME})
file(GLOB_RECURSE SRC_FILES "*/*.cpp" "*/*.hpp")
add_library(src_lib STATIC ${SRC_FILES})

add_executable(${BINARY} "main.cpp")
target_link_libraries(${BINARY} PUBLIC src_lib)
target_link_libraries(${BINARY} PUBLIC sfml-system sfml-window sfml-graphics)