#include <iostream>
#include "Fractions.h"

int main() {
    IFraction* defending_fraction = new DefendingFraction;
    IFraction* attacking_fraction = new AttackingFraction;

    // Применяем декоратор
    defending_fraction = new InformingDecorator(defending_fraction, "Defending");
    attacking_fraction = new InformingDecorator(attacking_fraction, "Attacking");

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

    defending_fraction->BuyUnit(0, HorseRiderFactory()); // первая фракция пытается купить юнита за 90,
                                                             // имея 60
    attacking_fraction->BuyUnit(0, SwordsmanFactory()); // вторая фракция пытается купить юнита за 50,
                                                            // имея 60
    std::cout << "End of example" << std::endl;

    delete defending_fraction;
    delete attacking_fraction;
}