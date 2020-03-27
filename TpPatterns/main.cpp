#include <iostream>
#include "AllUnits/IncludeAll.h"
#include "AllFractions/IncludeAll.h"

int main() {
    auto squad = new Squad;
    FractionFactory* fraction = new DefendingFraction;
    fraction->AddNewSquad(squad);
    fraction->AddBonusUnit(0);
    fraction->AddBonusUnit(0);
    fraction->Defend(50);
    fraction->Earn(0);
    delete fraction;
}