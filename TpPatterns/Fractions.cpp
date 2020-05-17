#include "Fractions.h"

Fraction::Fraction(UnitFactory* bonus_unit_factory): army(new Army), finance(new Finance), unit_id_counter(0), bonus_unit_factory(bonus_unit_factory) {}

Fraction::~Fraction() {
    delete army;
    delete finance;
    delete bonus_unit_factory;
}

void Fraction::CreateNewSquad() {
    Squad* new_squad = new Squad;
    army->AddNewSubnode(new_squad);
}

void Fraction::AddNewUnit(Unit* const& new_unit, std::size_t squad_number) {
    army->AddUnit(new_unit, squad_number);
}

void Fraction::AddBonusUnit(std::size_t squad_number) {
    Unit* new_unit = bonus_unit_factory->CreateUnit(unit_id_counter);
    ++unit_id_counter;
    AddNewUnit(new_unit, squad_number);
}

std::size_t Fraction::GetArmySize() const {
    return army->GetSize();
}

Finance Fraction::GetFinance() const {
    return *finance;
}

std::size_t Fraction::CountUnits() const {
    return army->CountUnits();
}

bool Fraction::BuyUnit(std::size_t squad_number, const UnitFactory& unit_factory) {
    if (finance->EnoughMoney(unit_factory.GetCost())) {
        Unit* new_unit = unit_factory.CreateUnit(unit_id_counter);
        AddNewUnit(new_unit, squad_number);
        ++unit_id_counter;
        finance->SpendMoney(unit_factory.GetCost());
        return true;
    } else {
        return false;
    }
}

//----------------------------------------------------------------------------------------------------------------------

AttackingFraction::AttackingFraction(): Fraction(new ArcherFactory) {}

void AttackingFraction::Attack(IFraction& other_fraction, std::size_t squad_number) const {
    double damage = army->GetSubnode(squad_number).GetDamage();
    other_fraction.Defend(damage * attacking_coefficient);
}

void AttackingFraction::Defend(double damage) {
    army->ToHit(damage * defending_coefficient);
}

void AttackingFraction::Earn(std::size_t squad_number) {
    double total_earnings = army->GetSubnode(squad_number).GetEarnings();
    finance->AddMoney(total_earnings);
}

//----------------------------------------------------------------------------------------------------------------------

DefendingFraction::DefendingFraction(): Fraction(new SwordsmanFactory) {}

void DefendingFraction::Attack(IFraction& other_fraction, std::size_t squad_number) const {
    double damage = army->GetSubnode(squad_number).GetDamage();
    other_fraction.Defend(damage * attacking_coefficient);
}

void DefendingFraction::Defend(double damage) {
    army->ToHit(damage * defending_coefficient);
}

void DefendingFraction::Earn(std::size_t squad_number) {
    double total_earnings = army->GetSubnode(squad_number).GetEarnings();
    finance->AddMoney(total_earnings);
}

//----------------------------------------------------------------------------------------------------------------------

EconomyFraction::EconomyFraction(): Fraction(new CivilianFactory) {}

void EconomyFraction::Attack(IFraction& other_fraction, std::size_t squad_number) const {
    double damage = army->GetSubnode(squad_number).GetDamage();
    other_fraction.Defend(damage);
}

void EconomyFraction::Defend(double damage) {
    army->ToHit(damage);
}

void EconomyFraction::Earn(std::size_t squad_number) {
    double total_earnings = army->GetSubnode(squad_number).GetEarnings();
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

void InformingDecorator::Attack(IFraction& other_fraction, std::size_t squad_number) const {
    std::cout << "Squad " << squad_number + 1 << " of fraction " << name << " attacks!" << std::endl;
    decorated_fraction->Attack(other_fraction, squad_number);
}

void InformingDecorator::Earn(std::size_t squad_number) {
    std::cout << "Squad " << squad_number + 1 << " of fraction " << name << " earns money." << std::endl;
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

void InformingDecorator::AddBonusUnit(std::size_t squad_number) {
    decorated_fraction->AddBonusUnit(squad_number);
    std::cout << "In squad " << squad_number + 1 << " of fraction " << name << " added bonus unit." << std::endl;
}

bool InformingDecorator::BuyUnit(std::size_t squad_number, const UnitFactory& unit_factory) {
    bool unit_bought = decorated_fraction->BuyUnit(squad_number, unit_factory);
    if (unit_bought) {
        std::cout << "In squad " << squad_number + 1 << " of fraction " << name << " bought new " << unit_factory.GetType() << "." << std::endl;
    } else {
        std::cout << "Not enough money" << std::endl;
    }
    return unit_bought;
}

std::size_t InformingDecorator::GetArmySize() const {
    return decorated_fraction->GetArmySize();
}

Finance InformingDecorator::GetFinance() const {
    return decorated_fraction->GetFinance();
}

std::size_t InformingDecorator::CountUnits() const {
    return decorated_fraction->CountUnits();
}