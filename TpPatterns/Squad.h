#pragma once
#include "Units.h"
#include "ArmyNode.h"
#include <vector>
#include <cstddef>


class Squad: public CompositeNode {
public:
    explicit Squad() = default;

    void ToHit(double damage) override;

private:
    void deleteDeadUnits();
};
