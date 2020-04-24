#include "Squad.h"
#include "Units.h"
#include <algorithm>

void Squad::ToHit(double damage) {
    CompositeNode::ToHit(damage);
    deleteDeadUnits();
}

void Squad::deleteDeadUnits() {
    for (ArmyNode *subnode: subnodes) {
        try {
            Unit &unit = dynamic_cast<Unit &>(*subnode);
            if (unit.IsDead()) {
                delete subnode;
                subnode = nullptr;
            }
        } catch (const std::bad_cast &exception) {
            std::cerr << "Squad contains non-Unit object" << std::endl;
        }
    }
    auto iterator = std::find(subnodes.begin(), subnodes.end(), nullptr);
    while (iterator != subnodes.end()) {
        subnodes.erase(iterator);
    }
}
