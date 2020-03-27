#include "DefendingFraction.h"

Unit* DefendingFraction::CreateBonusUnit() {
    Unit* new_unit = new Swordsman(unit_id_counter);
    ++unit_id_counter;
    return  new_unit;
}

void DefendingFraction::Attack(FractionFactory &other_fraction, size_t squad_number) const {
    double total_damage = army->GetSquad(squad_number).GetTotalDamage();
    size_t other_army_size = other_fraction.GetArmySize();
    double damage = total_damage / other_army_size;
    other_fraction.Defend(damage * 0.9);
}

void DefendingFraction::Defend(double damage) {
    army->ToHit(damage * 0.9);
}

void DefendingFraction::Earn(size_t squad_number) {
    double total_earnings = army->GetSquad(squad_number).GetTotalEarnings();
    finance->AddMoney(total_earnings);
}