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

std::string Civilian::GetType() const {
    return "Civilian";
}

std::string Civilian::GetInfo() {
    return "Civilian can't to take part in the battles, use it to earn money.\n";
}

//----------------------------------------------------------------------------------------------------------------------

Archer::Archer(int id): Unit(id, initial_health, initial_damage, initial_earnings, initial_protection) {}

std::string Archer::GetType() const {
    return "Archer";
}

std::string Archer::GetInfo() {
    return "Archer has a big damage, but he has the worst protection and health.\n";
}

//----------------------------------------------------------------------------------------------------------------------

HorseRider::HorseRider(int id): Unit(id, initial_health, initial_damage, initial_earnings, initial_protection) {}

std::string HorseRider::GetType() const {
    return "Horse rider";
}

std::string HorseRider::GetInfo() {
    return "Horse rider has a big damage, but he has the worst protection and health.\n";
}

//----------------------------------------------------------------------------------------------------------------------

Swordsman::Swordsman(int id): Unit(id, initial_health, initial_damage, initial_earnings, initial_protection) {}

std::string Swordsman::GetType() const {
    return "Swordsman";
}

std::string Swordsman::GetInfo() {
    return "Swordsman has a good protection and health, but not very big damage.\n";
}

