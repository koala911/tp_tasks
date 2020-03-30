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
    double GetHealth() const;
    double GetDamage() const;
    int GetId() const;
    double GetProtection() const;
    double GetEarnings() const;

    void ToHit(double damage);
    bool IsDead() const;

private:
    const int id;
    double health;
    double damage;
    double earnings;
    double protection;
};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

//----------------------------------------------------------------------------------------------------------------------

class Civilian: public Unit {
public:
    explicit Civilian (int id);

    std::string GetType() const override;

    constexpr static const double cost = 40;
    constexpr static const double initial_health = 100;
    constexpr static const double initial_damage = 0;
    constexpr static const double initial_earnings = 50;
    constexpr static const double initial_protection = 0;
    static std::string GetInfo();
};

//----------------------------------------------------------------------------------------------------------------------

class Archer: public Unit {
public:
    explicit Archer (int id);

    std::string GetType() const override;

    constexpr static const double cost = 60;
    constexpr static const double initial_health = 130;
    constexpr static const double initial_damage = 85;
    constexpr static const double initial_earnings = 15;
    constexpr static const double initial_protection = 0.4;
    static std::string GetInfo();
};

//----------------------------------------------------------------------------------------------------------------------

class HorseRider: public Unit {
public:
    explicit HorseRider (int id);

    std::string GetType() const override;

    constexpr static const double cost = 90;
    constexpr static const double initial_health = 200;
    constexpr static const double initial_damage = 90;
    constexpr static const double initial_earnings = 10;
    constexpr static const double initial_protection = 0.5;
    static std::string GetInfo();
};

//----------------------------------------------------------------------------------------------------------------------

class Swordsman: public Unit {
public:
    explicit Swordsman (int id);

    std::string GetType() const override;

    constexpr static const double cost = 50;
    constexpr static const double initial_health = 200;
    constexpr static const double initial_damage = 60;
    constexpr static const double initial_earnings = 15;
    constexpr static const double initial_protection = 0.6;
    static std::string GetInfo();
};