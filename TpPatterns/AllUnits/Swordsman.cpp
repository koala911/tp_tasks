#include "Swordsman.h"

Swordsman::Swordsman(int id): Unit(id, 200, 60, 15, 0.6) {}

std::string Swordsman::GetType() const {
    return "Swordsman";
}

std::string Swordsman::GetInfo() const {
    return "Swordsman has a good protection and health, but not very big damage.\n";
}
