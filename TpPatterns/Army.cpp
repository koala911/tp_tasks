#include "Army.h"
#include <algorithm>


void Army::AddUnit(Unit* const& new_unit, std::size_t squad_number) {
    try {
        Squad* squad = dynamic_cast<Squad*>(subnodes[squad_number]);
        squad->AddNewSubnode(new_unit);
    } catch (const std::bad_cast &exception) {
        std::cerr << "Army contains non-Squad object" << std::endl;
    }
}
