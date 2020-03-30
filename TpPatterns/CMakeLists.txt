cmake_minimum_required(VERSION 3.15)
project(TpPatterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(TpPatterns
        main.cpp
        Units.cpp Units.h
        Squad.cpp Squad.h
        Army.cpp Army.h
        Fractions.cpp Fractions.h
        Finance.cpp Finance.h
        Fractions.h Fractions.cpp
        )