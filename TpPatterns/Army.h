#pragma once
#include "Squad.h"
#include <vector>

class Army {
public:
    explicit Army() = default;
    ~Army();

    size_t GetNumberOfSquads() const;
    size_t GetNumberOfUnits() const;
    double GetTotalDamage() const;
    double GetTotalEarnings() const;
    bool IsEmpty() const;
    void AddSquad(Squad* const& new_squad);
    void AddUnit(Unit* const& new_unit, size_t squad_number);
    void ToHit(double damage);
    const Squad& GetSquad(size_t i);

private:
    std::vector<Squad*> squads;
    double total_damage = 0;
    double total_earnings = 0;

    void deleteNullPointers();
};
