cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/arm-linux-gnueabihf-g++)

project(SimpleLibrary)


include_directories(include)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
add_subdirectory(src)
set_target_properties(buffer PROPERTIES PUBLIC_HEADER include/buffer.h)

add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)
#add_executable(buffer_header include/buffer.h)

target_link_libraries(MainLib buffer)

install(    
        TARGETS Main MainLib 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION bin
        ARCHIVE DESTINATION bin
        INCLUDES DESTINATION bin
    )
#install(TARGETS MainLib DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)