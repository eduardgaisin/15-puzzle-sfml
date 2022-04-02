cmake_minimum_required(VERSION 3.18)
project(15-puzzle-sfml)

# Default Debug build
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  "${CMAKE_BINARY_DIR}/target")

set(SFML_USE_STATIC_LIBS ON)
find_package(SFML 2.5 REQUIRED network audio graphics window system)
include_directories(SFMLClicker PUBLIC ${SFML_INCLUDE_DIR})

include_directories(
    "src"
    "src/App"
    "src/Game"
    "src/Units"
)

add_subdirectory("src")

add_subdirectory("font")