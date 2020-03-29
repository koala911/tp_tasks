add_library(buffer SHARED buffer.cpp)
install(    
        TARGETS buffer 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include
        INCLUDES DESTINATION ../incude
        )
