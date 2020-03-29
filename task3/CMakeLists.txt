cmake_minimum_required(VERSION 3.0)
if (ARM_BUILD)
    set(CMAKE_SYSTEM_PROCESSOR arm)
    set(CMAKE_C_COMPILER ${TOOLCHAIN}/arm-linux-gnueabihf-gcc)
    set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/arm-linux-gnueabihf-g++)
    set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
endif()

project(SimpleLibrary)


include_directories(include)

install(FILES ${SimpleLibrary_SOURCE_DIR}/include/buffer.h DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
add_subdirectory(src)
set_target_properties(buffer PROPERTIES PUBLIC_HEADER include/buffer.h)


set(CMAKE_INSTALL_RPATH "$ORIGIN/../bin")
set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)

add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)
#add_executable(buffer_header include/buffer.h)

target_link_libraries(MainLib buffer)

if (ARM_BUILD)
    install(TARGETS Main MainLib DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
endif()