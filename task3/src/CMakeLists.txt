add_library(buffer SHARED buffer.cpp)
install(    
        TARGETS buffer 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION bin
        ARCHIVE DESTINATION bin
        PUBLIC_HEADER DESTINATION bin
        INCLUDES DESTINATION bin
        )
