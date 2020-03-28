cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/arm-linux-gnueabihf-g++)

project(SimpleLibrary)


include_directories(include)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)
add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)
add_executable(buffer include/buffer.h)

target_link_libraries(MainLib buffer)

install(TARGETS Main DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(TARGETS MainLib DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(TARGETS buffer DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
