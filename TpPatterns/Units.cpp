#include "Units.h"

Unit::Unit(int id, double health, double damage, double earnings, double protection):
            id(id), health(health), damage(damage), earnings(earnings), protection(protection) {}

double Unit::GetHealth() const {
    return health;
}

double Unit::GetDamage() const {
    return damage;
}

double Unit::GetEarnings() const {
    return earnings;
}

double Unit::GetProtection() const {
    return protection;
}

int Unit::GetId() const {
    return id;
}

void Unit::ToHit(double damage) {
    health -= damage * (1 - protection);
    if (health < 0) {
        health = 0;
    }
}

bool Unit::IsDead() const {
    return (health <= 0);
}

std::size_t Unit::CountUnits() const {
    return 1;
}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.GetType() << " " << unit.GetId() << std::endl;
    out << "Health: " << unit.GetHealth() << std::endl;
    out << "Damage: " << unit.GetDamage() << std::endl;
    out << "Protection: " << unit.GetProtection() << std::endl;
    out << "Earnings: " << unit.GetEarnings() << std::endl;
    out << std::endl;
    return out;
}

//----------------------------------------------------------------------------------------------------------------------

Civilian::Civilian(int id): Unit(id, initial_health, initial_damage, initial_earnings, initial_protection) {}

const std::string Civilian::type = "Civilian";

std::string Civilian::GetType() const {
    return type;
}

std::string Civilian::GetInfo() {
    return "Civilian can't to take part in the battles, use it to earn money.\n";
}

//----------------------------------------------------------------------------------------------------------------------

Archer::Archer(int id): Unit(id, initial_health, initial_damage, initial_earnings, initial_protection) {}

const std::string Archer::type = "Archer";

std::string Archer::GetType() const {
    return type;
}

std::string Archer::GetInfo() {
    return "Archer has a big damage, but he has the worst protection and health.\n";
}

//----------------------------------------------------------------------------------------------------------------------

HorseRider::HorseRider(int id): Unit(id, initial_health, initial_damage, initial_earnings, initial_protection) {}

const std::string HorseRider::type = "Horse Rider";

std::string HorseRider::GetType() const {
    return type;
}

std::string HorseRider::GetInfo() {
    return "Horse rider has a big damage, but he has the worst protection and health.\n";
}

//----------------------------------------------------------------------------------------------------------------------

Swordsman::Swordsman(int id): Unit(id, initial_health, initial_damage, initial_earnings, initial_protection) {}

const std::string Swordsman::type = "Swordsman";

std::string Swordsman::GetType() const {
    return type;
}

std::string Swordsman::GetInfo() {
    return "Swordsman has a good protection and health, but not very big damage.\n";
}

//----------------------------------------------------------------------------------------------------------------------

double CivilianFactory::GetCost() const {
    return Civilian::cost;
}

Unit* CivilianFactory::CreateUnit(int id) const {
    return new Civilian(id);
}

std::string CivilianFactory::GetType() const {
    return Civilian::type;
}

//----------------------------------------------------------------------------------------------------------------------

double ArcherFactory::GetCost() const {
    return Archer::cost;
}

Unit* ArcherFactory::CreateUnit(int id) const {
    return new Archer(id);
}

std::string ArcherFactory::GetType() const {
    return Archer::type;
}

//----------------------------------------------------------------------------------------------------------------------

double HorseRiderFactory::GetCost() const {
    return HorseRider::cost;
}

Unit* HorseRiderFactory::CreateUnit(int id) const {
    return new HorseRider(id);
}

std::string HorseRiderFactory::GetType() const {
    return HorseRider::type;
}

//----------------------------------------------------------------------------------------------------------------------

double SwordsmanFactory::GetCost() const {
    return Swordsman::cost;
}

Unit* SwordsmanFactory::CreateUnit(int id) const {
    return new Swordsman(id);
}

std::string SwordsmanFactory::GetType() const {
    return Swordsman::type;
}
