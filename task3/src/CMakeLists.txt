add_library(buffer SHARED buffer.cpp)
install(    
        TARGETS buffer 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION /usr/local/lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION /usr/local/include
        INCLUDES DESTINATION ../incude
        )
