#include "Squad.h"
#include "Units.h"
#include <algorithm>

Squad::~Squad() {
    for (const auto& unit: units) {
        delete unit;
    }
}

size_t Squad::GetSize() const {
    return units.size();
}

bool Squad::IsEmpty() const {
    return units.empty();
}

void Squad::AddUnit(Unit* const& new_unit) {
    units.push_back(const_cast<Unit*>(new_unit));
    total_damage += new_unit->GetDamage();
    total_earnings += new_unit->GetEarnings();
}

void Squad::ToHit(double damage) {
    for (Unit* unit: units) {
        unit->ToHit(damage);
        if (unit->IsDead()) {
            total_damage -= unit->GetDamage();
            total_earnings -= unit->GetEarnings();
            delete unit;
            unit = nullptr;
        }
    }
    deleteNullPointers();
}

void Squad::deleteNullPointers() {
    auto iterator = std::find(units.begin(), units.end(), nullptr);
    while (iterator != units.end()) {
        units.erase(iterator);
    }
}

double Squad::GetTotalDamage() const {
    return total_damage;
}

double Squad::GetTotalEarnings() const {
    return total_earnings;
}

