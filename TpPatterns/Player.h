#pragma once

#include "Fractions.h"
#include <string>

class Player {
public:
    explicit Player(int id);
    explicit Player(int id, Fraction* const& fraction, const std::string& name);
    ~Player();

private:
    const int id;
    Fraction* fraction;
    std::string name;

    void initializeName();
    void initializeFraction();
};
