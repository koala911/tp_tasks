#pragma once
#include <string>
#include <functional>
#include <iostream>

class Unit {
public:
    Unit() = delete;
    explicit Unit(int id, double health, double damage, double earnings, double protection);
    virtual ~Unit() = default;
    virtual std::string GetType() const = 0;
    virtual std::string GetInfo() const = 0;
    double GetHealth() const;
    double GetDamage() const;
    int GetId() const;
    double GetProtection() const;
    double GetEarnings() const;

    void ToHit(double damage);
    bool IsDead() const;

private:
    int id;
    double health;
    double damage;
    double earnings;
    double protection;
};


std::ostream& operator<<(std::ostream& out, const Unit& unit);