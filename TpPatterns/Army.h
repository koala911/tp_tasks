#pragma once
#include "Squad.h"
#include <vector>
#include <cstddef>

class Army: public CompositeNode {
public:
    explicit Army() = default;

    void AddUnit(Unit* const& new_unit, std::size_t squad_number);
};
