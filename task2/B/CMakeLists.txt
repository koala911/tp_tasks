cmake_minimum_required(VERSION 3.16)

project(lib)

set(SOURCE_LIB lib.cpp)

add_library(lib SHARED ${SOURCE_LIB})
