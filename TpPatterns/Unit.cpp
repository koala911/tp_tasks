#include "Unit.h"

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
