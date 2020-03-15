cmake_minimum_required(VERSION 3.10)

project(lib)

set(SOURCE_LIB lib.cpp)

add_library(lib SHARED ${SOURCE_LIB})
