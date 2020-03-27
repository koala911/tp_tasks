#pragma once
#include "../Unit.h"

class Swordsman: public Unit {
public:
    explicit Swordsman (int id);

    constexpr static const double cost = 50;

    std::string GetType() const override;
    std::string GetInfo() const override;
};

