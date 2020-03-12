cmake_minimum_required(VERSION 2.8)

project(hello_world)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(${CMAKE_SOURCE_DIR})

add_custom_command(
    OUTPUT ${CMAKE_SOURCE_DIR}/A/index.h
    COMMAND python3 ${CMAKE_SOURCE_DIR}/A/preparing.py
)

add_custom_target(py_script ALL DEPENDS ${CMAKE_SOURCE_DIR}/A/index.h)

add_executable(main C/main.cpp C/main.h A/index.h B/lib.cpp B/lib.h)

add_subdirectory(B)

target_link_libraries(main lib)