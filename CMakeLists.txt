cmake_minimum_required(VERSION 3.10)

project(lame2D VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples)
set(CMAKE_CXX_FLAGS "-O3")
# set(CMAKE_CXX_FLAGS "-ggdb")

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories("include/")

file(GLOB_RECURSE SOURCES "src/*.cpp" "include/*.hpp")

add_library(lame2D STATIC ${SOURCES})

target_link_libraries(lame2D ${SDL2_LIBRARIES})

add_subdirectory(examples)
