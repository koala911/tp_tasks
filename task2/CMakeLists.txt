cmake_minimum_required(VERSION 2.8)

project(hello_world)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(A B)

add_executable(main C/main.cpp)

add_subdirectory(B)

target_link_libraries(main lib)