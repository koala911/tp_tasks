#include "AttackingFraction.h"

Unit* AttackingFraction::CreateBonusUnit() {
    Unit* new_unit = new Archer(unit_id_counter);
    ++unit_id_counter;
    return  new_unit;
}

void AttackingFraction::Attack(FractionFactory &other_fraction, size_t squad_number) const {
    double total_damage = army->GetSquad(squad_number).GetTotalDamage();
    size_t other_army_size = other_fraction.GetArmySize();
    double damage = total_damage / other_army_size;
    other_fraction.Defend(damage * 1.1);
}

void AttackingFraction::Defend(double damage) {
    army->ToHit(damage * 1.1);
}

void AttackingFraction::Earn(size_t squad_number) {
    double total_earnings = army->GetSquad(squad_number).GetTotalEarnings();
    finance->AddMoney(total_earnings);
}