#pragma once
#include "Unit.h"
#include <vector>

class Squad {
public:
    explicit Squad() = default;
    ~Squad();

    size_t GetSize() const;
    double GetTotalDamage() const;
    double GetTotalEarnings() const;
    bool IsEmpty() const;
    void AddUnit(Unit* const& new_unit);
    void ToHit(double damage);

private:
    std::vector<Unit*> units;
    double total_damage = 0;
    double total_earnings = 0;

    void deleteNullPointers();
};
