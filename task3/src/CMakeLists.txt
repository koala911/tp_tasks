add_library(buffer SHARED buffer.cpp)
install(    
        TARGETS buffer 
        #RUNTIME DESTINATION bin
        LIBRARY DESTINATION ${CMAKE_SYSROOT}/lib
        #ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION ${CMAKE_SYSROOT}/include
        INCLUDES DESTINATION  ${CMAKE_SYSROOT}/include
        )
