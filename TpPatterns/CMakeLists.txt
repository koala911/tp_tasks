cmake_minimum_required(VERSION 3.15)
project(TpPatterns)

set(CMAKE_CXX_STANDARD 14)

add_executable(TpPatterns main.cpp Unit.cpp Unit.h AllUnits/Civilian.cpp AllUnits/Civilian.h AllUnits/Swordsman.cpp AllUnits/Swordsman.h AllUnits/Archer.cpp AllUnits/Archer.h AllUnits/HorseRider.cpp AllUnits/HorseRider.h AllUnits/IncludeAll.h Squad.cpp Squad.h Army.cpp Army.h FractionFactory.cpp FractionFactory.h Finance.cpp Finance.h AllFractions/AttackingFraction.cpp AllFractions/AttackingFraction.h AllFractions/DefendingFraction.cpp AllFractions/DefendingFraction.h AllFractions/EconomyFraction.cpp AllFractions/EconomyFraction.h AllFractions/IncludeAll.h Event.cpp Event.h)