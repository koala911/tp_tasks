#include "Fractions.h"

Fraction::Fraction(): army(new Army), finance(new Finance), unit_id_counter(0) {}

Fraction::~Fraction() {
    delete army;
    delete finance;
}

void Fraction::CreateNewSquad() {
    Squad* new_squad = new Squad;
    army->AddSquad(new_squad);
}

void Fraction::AddNewUnit(Unit* const& new_unit, size_t squad_number) {
    army->AddUnit(new_unit, squad_number);
}

void Fraction::AddBonusUnit(size_t squad_number) {
    Unit* new_unit = CreateBonusUnit();
    AddNewUnit(new_unit, squad_number);
}

size_t Fraction::GetArmySize() const {
    return army->GetNumberOfUnits();
}

//----------------------------------------------------------------------------------------------------------------------

Unit* AttackingFraction::CreateBonusUnit() {
    Unit* new_unit = new Archer(unit_id_counter);
    ++unit_id_counter;
    return  new_unit;
}

void AttackingFraction::Attack(Fraction& other_fraction, size_t squad_number) const {
    double total_damage = army->GetSquad(squad_number).GetTotalDamage();
    size_t other_army_size = other_fraction.GetArmySize();
    double damage = total_damage / other_army_size;
    other_fraction.Defend(damage * attacking_coefficient);
}

void AttackingFraction::Defend(double damage) {
    army->ToHit(damage * defending_coefficient);
}

void AttackingFraction::Earn(size_t squad_number) {
    double total_earnings = army->GetSquad(squad_number).GetTotalEarnings();
    finance->AddMoney(total_earnings);
}

//----------------------------------------------------------------------------------------------------------------------

Unit* DefendingFraction::CreateBonusUnit() {
    Unit* new_unit = new Swordsman(unit_id_counter);
    ++unit_id_counter;
    return  new_unit;
}

void DefendingFraction::Attack(Fraction& other_fraction, size_t squad_number) const {
    double total_damage = army->GetSquad(squad_number).GetTotalDamage();
    size_t other_army_size = other_fraction.GetArmySize();
    double damage = total_damage / other_army_size;
    other_fraction.Defend(damage * attacking_coefficient);
}

void DefendingFraction::Defend(double damage) {
    army->ToHit(damage * defending_coefficient);
}

void DefendingFraction::Earn(size_t squad_number) {
    double total_earnings = army->GetSquad(squad_number).GetTotalEarnings();
    finance->AddMoney(total_earnings);
}

//----------------------------------------------------------------------------------------------------------------------

Unit* EconomyFraction::CreateBonusUnit() {
    Unit* new_unit = new Swordsman(unit_id_counter);
    ++unit_id_counter;
    return  new_unit;
}

void EconomyFraction::Attack(Fraction& other_fraction, size_t squad_number) const {
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
    finance->AddMoney(total_earnings * earning_coefficient);
}
