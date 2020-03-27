#include "EconomyFraction.h"

Unit* EconomyFraction::CreateBonusUnit() {
    Unit* new_unit = new Swordsman(unit_id_counter);
    ++unit_id_counter;
    return  new_unit;
}

void EconomyFraction::Attack(FractionFactory &other_fraction, size_t squad_number) const {
    double total_damage = army->GetSquad(squad_number).GetTotalDamage();
    size_t other_army_size = other_fraction.GetArmySize();
    double damage = total_damage / other_army_size;
    other_fraction.Defend(damage);
}

void EconomyFraction::Defend(double damage) {
    army->ToHit(damage);
}

void EconomyFraction::Earn(size_t squad_number) {
    double total_earnings = army->GetSquad(squad_number).GetTotalEarnings();
    finance->AddMoney(total_earnings * 1.1);
}