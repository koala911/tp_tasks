#include "Army.h"
#include <algorithm>

Army::~Army() {
    for (Squad* squad: squads) {
        delete squad;
    }
}

size_t Army::GetNumberOfSquads() const {
    return squads.size();
}

size_t Army::GetNumberOfUnits() const {
    size_t result = 0;
    for (Squad* squad: squads) {
        result += squad->GetSize();
    }
    return result;
}

bool Army::IsEmpty() const {
    return squads.empty();
}

void Army::AddSquad(Squad* const& new_squad) {
    squads.push_back(new_squad);
    total_damage += new_squad->GetTotalDamage();
    total_earnings += new_squad->GetTotalEarnings();
}

void Army::AddUnit(Unit *const &new_unit, size_t squad_number) {
    squads[squad_number]->AddUnit(new_unit);
    total_damage += new_unit->GetDamage();
    total_earnings += new_unit->GetEarnings();
}

void Army::ToHit(double damage) {
    for (Squad* squad: squads) {
        squad->ToHit(damage);
        if (squad->IsEmpty()) {
            total_damage -= squad->GetTotalDamage();
            total_earnings -= squad->GetTotalEarnings();
            delete squad;
            squad = nullptr;
        }
    }
    deleteNullPointers();
}

void Army::deleteNullPointers() {
    auto iterator = std::find(squads.begin(), squads.end(), nullptr);
    while (iterator != squads.end()) {
        squads.erase(iterator);
    }
}

double Army::GetTotalDamage() const {
    return total_damage;
}

double Army::GetTotalEarnings() const {
    return total_earnings;
}

const Squad& Army::GetSquad(size_t i) {
    return *squads[i];
}


