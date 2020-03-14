cmake_minimum_required(VERSION 3.10)

project(hello_world)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${GTEST_INCLUDE_DIRS})

add_custom_command(
    OUTPUT ${CMAKE_SOURCE_DIR}/A/index.h
    COMMAND python3 ${CMAKE_SOURCE_DIR}/A/preparing.py
)

add_custom_target(py_script ALL DEPENDS ${CMAKE_SOURCE_DIR}/A/index.h)

add_executable(main C/main.cpp)
add_executable(main_test C/main_test.cpp)

add_subdirectory(B)

target_link_libraries(main lib)
target_link_libraries(main_test ${GTEST_LIBRARIES} Threads::Threads)