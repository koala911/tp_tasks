#include <iostream>
#include "Units.h"
#include "Fractions.h"

int main() {
    Fraction* defending_fraction = new DefendingFraction;
    Fraction* attacking_fraction = new AttackingFraction;
    defending_fraction->CreateNewSquad();
    defending_fraction->AddBonusUnit(0);
    defending_fraction->AddBonusUnit(0);
    attacking_fraction->CreateNewSquad();
    attacking_fraction->AddBonusUnit(0);
    attacking_fraction->AddBonusUnit(0);
    defending_fraction->Attack(*attacking_fraction, 0);
    defending_fraction->Earn(0);
    defending_fraction->Earn(0);
    attacking_fraction->Earn(0);
    attacking_fraction->Earn(0);
    defending_fraction->BuyUnit<HorseRider>(0);
    attacking_fraction->BuyUnit<Swordsman>(0);
    std::cout << "End if example" << std::endl;
    delete defending_fraction;
    delete attacking_fraction;
}