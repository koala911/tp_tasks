#include "Civilian.h"

Civilian::Civilian(int id): Unit(id, 100, 0, 50, 0) {}

std::string Civilian::GetType() const {
    return "Civilian";
}

std::string Civilian::GetInfo() const {
    return "Civilian can't to take part in the battles, use it to earn money.\n";
}

