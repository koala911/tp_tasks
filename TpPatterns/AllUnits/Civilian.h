#pragma once
#include "../Unit.h"

class Civilian: public Unit {
public:
    explicit Civilian (int id);

    constexpr static const double cost = 40;

    std::string GetType() const override;
    std::string GetInfo() const override;
};
