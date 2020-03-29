add_library(buffer SHARED buffer.cpp)
install(    
        TARGETS buffer 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION bin
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION ../incude
        INCLUDES DESTINATION ../incude
        )
