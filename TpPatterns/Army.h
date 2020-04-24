#pragma once
#include "Squad.h"
#include <vector>

class Army: public CompositeNode {
public:
    explicit Army() = default;

    void AddUnit(Unit* const& new_unit, size_t squad_number);
};
