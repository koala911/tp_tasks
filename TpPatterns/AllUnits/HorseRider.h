#pragma once
#include "../Unit.h"

class HorseRider: public Unit {
public:
    explicit HorseRider (int id);

    constexpr static const double cost = 90;

    std::string GetType() const override;
    std::string GetInfo() const override;
};
