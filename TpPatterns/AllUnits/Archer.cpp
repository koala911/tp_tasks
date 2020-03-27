#include "Archer.h"

Archer::Archer(int id): Unit(id, 130, 85, 15, 0.4) {}

std::string Archer::GetType() const {
    return "Archer";
}

std::string Archer::GetInfo() const {
    return "Archer has a big damage, but he has the worst protection and health.\n";
}

