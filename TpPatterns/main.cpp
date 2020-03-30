#include <iostream>
#include "Units.h"
#include "Fractions.h"

int main() {
    Fraction* defending_fraction = new DefendingFraction;
    Fraction* attacking_fraction = new AttackingFraction;

    defending_fraction->CreateNewSquad(); // создаем первый отряд в первой фракции

    defending_fraction->AddBonusUnit(0); // добавлем двух
    defending_fraction->AddBonusUnit(0); // бонусных юнитов (мечников)

    attacking_fraction->CreateNewSquad(); // создаем первый отряд во второй фракции

    attacking_fraction->AddBonusUnit(0); // добавлем двух
    attacking_fraction->AddBonusUnit(0); // бонусных юнитов (лучников)

    defending_fraction->Attack(*attacking_fraction, 0); // первая фракция атакует вторую

    defending_fraction->Earn(0); // первая фракция
    defending_fraction->Earn(0); // зарабатывает деньги

    attacking_fraction->Earn(0); // вторая фракция
    attacking_fraction->Earn(0); // зарабатывает деньги

    defending_fraction->BuyUnit<HorseRider>(0); // первая фракция пытается купить юнита за 90,
                                                             // имея 60
    attacking_fraction->BuyUnit<Swordsman>(0); // вторая фракция пытается купить юнита за 50,
                                                            // имея 60
    std::cout << "End if example" << std::endl;

    delete defending_fraction;
    delete attacking_fraction;
}