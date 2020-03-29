add_library(buffer SHARED buffer.cpp)
install(    
        TARGETS buffer 
        RUNTIME DESTINATION /usr/local/bin
        LIBRARY DESTINATION /usr/local/bin
        ARCHIVE DESTINATION /usr/local/lib
        PUBLIC_HEADER DESTINATION /usr/local/include
        INCLUDES DESTINATION /usr/local/include
        )
