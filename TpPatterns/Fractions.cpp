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

bool Fraction::BuyUnit(size_t squad_number, const UnitFactory& unit_factory) {
    if (finance->EnoughMoney(unit_factory.GetCost())) {
        Unit* new_unit = unit_factory.CreateUnit(unit_id_counter);
        AddNewUnit(new_unit, squad_number);
        ++unit_id_counter;
        finance->SpendMoney(unit_factory.GetCost());
        return true;
    } else {
        std::cout << "Not enough money" << std::endl;
        return false;
    }
}

//----------------------------------------------------------------------------------------------------------------------

Unit* AttackingFraction::CreateBonusUnit() {
    Unit* new_unit = new Archer(unit_id_counter);
    ++unit_id_counter;
    return  new_unit;
}

void AttackingFraction::Attack(IFraction& other_fraction, size_t squad_number) const {
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

void DefendingFraction::Attack(IFraction& other_fraction, size_t squad_number) const {
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

void EconomyFraction::Attack(IFraction& other_fraction, size_t squad_number) const {
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

//----------------------------------------------------------------------------------------------------------------------

InformingDecorator::InformingDecorator(IFraction* const& fraction_to_decorate, const std::string& name): name(name) {
    decorated_fraction = dynamic_cast<Fraction*>(fraction_to_decorate);
    if (decorated_fraction == nullptr) {
        InformingDecorator* already_decorated_fraction = dynamic_cast<InformingDecorator*>(fraction_to_decorate);
        decorated_fraction = already_decorated_fraction->decorated_fraction;
        std::cerr << "Attempt to decorate already decorated fraction" << std::endl;
    }
}

InformingDecorator::~InformingDecorator() {
    delete decorated_fraction;
}

void InformingDecorator::Attack(IFraction& other_fraction, size_t squad_number) const {
    std::cout << "Squad " << squad_number << " of fraction " << name << " attacks!" << std::endl;
    decorated_fraction->Attack(other_fraction, squad_number);
}

void InformingDecorator::Earn(size_t squad_number) {
    std::cout << "Squad " << squad_number << " of fraction " << name << " earns money." << std::endl;
    decorated_fraction->Earn(squad_number);
}

void InformingDecorator::Defend(double damage) {
    std::cout << "Fraction " << name << " defends." << std::endl;
    decorated_fraction->Defend(damage);
}

void InformingDecorator::CreateNewSquad() {
    decorated_fraction->CreateNewSquad();
    std::cout << "Fraction " << name << " created new squad." << std::endl;
}

void InformingDecorator::AddBonusUnit(size_t squad_number) {
    decorated_fraction->AddBonusUnit(squad_number);
    std::cout << "In squad " << squad_number << " of fraction " << name << " added bonus unit." << std::endl;
}

bool InformingDecorator::BuyUnit(size_t squad_number, const UnitFactory& unit_factory) {
    bool unit_bought = decorated_fraction->BuyUnit(squad_number, unit_factory);
    if (unit_bought) {
        std::cout << "In squad " << squad_number << " of fraction " << name << " bought new " << unit_factory.GetType() << "." << std::endl;
    }
    return unit_bought;
}

size_t InformingDecorator::GetArmySize() const {
    return decorated_fraction->GetArmySize();
}