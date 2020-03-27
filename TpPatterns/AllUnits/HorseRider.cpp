#include "HorseRider.h"

HorseRider::HorseRider(int id): Unit(id, 200, 90, 10, 0.5) {}

std::string HorseRider::GetType() const {
    return "Horse rider";
}

std::string HorseRider::GetInfo() const {
    return "Horse rider has a big damage, but he has the worst protection and health.\n";
}