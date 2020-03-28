add_library(buffer SHARED buffer.cpp)
install(    
        TARGETS buffer 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )