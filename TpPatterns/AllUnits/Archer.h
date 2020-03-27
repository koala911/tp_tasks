#pragma once
#include "../Unit.h"

class Archer: public Unit {
public:
    explicit Archer (int id);

    constexpr static const double cost = 60;

    std::string GetType() const override;
    std::string GetInfo() const override;
};
