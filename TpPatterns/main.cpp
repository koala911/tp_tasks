#include <iostream>
#include "Units.h"
#include "Fractions.h"

int main() {
    auto squad = new Squad;
    Fraction* fraction = new DefendingFraction;
    fraction->AddNewSquad(squad);
    fraction->AddBonusUnit(0);
    fraction->AddBonusUnit(0);
    fraction->Defend(50);
    fraction->Earn(0);
    fraction->BuyUnit<HorseRider>(0);
    delete fraction;
}