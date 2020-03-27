#pragma once

#include "../FractionFactory.h"

class DefendingFraction: public FractionFactory {
public:
    void Attack(FractionFactory& other_fraction, size_t squad_number) const override;
    void Earn(size_t squad_number) override ;
    void Defend(double damage) override;

private:
    Unit* CreateBonusUnit() override;
};


