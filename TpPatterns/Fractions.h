#pragma once

#include "Army.h"
#include "Units.h"
#include "Finance.h"

class Fraction {
public:
    explicit Fraction();
    virtual ~Fraction();

    virtual void Attack(Fraction& other_fraction, size_t squad_number) const = 0;
    virtual void Earn(size_t squad_number) = 0;
    virtual void Defend(double damage) = 0;

    void CreateNewSquad();
    void AddBonusUnit(size_t squad_number);
    template<class UnitToBuy>
    void BuyUnit(size_t squad_number);
    size_t GetArmySize() const;

protected:
    Army* const army;
    Finance* const finance;
    int unit_id_counter;

    void AddNewUnit(Unit* const& new_unit, size_t squad_number);
    virtual Unit* CreateBonusUnit() = 0; // фабричный метод для создания нового бонусного юнита
};

template<class UnitToBuy>
void Fraction::BuyUnit(size_t squad_number) {
    if (finance->EnoughMoney(UnitToBuy::cost)) {
        Unit* new_unit = new UnitToBuy(unit_id_counter);
        AddNewUnit(new_unit, squad_number);
        ++unit_id_counter;
        finance->SpendMoney(UnitToBuy::cost);
    } else {
        std::cerr << "Not enough money" << std::endl;
    }
}

//----------------------------------------------------------------------------------------------------------------------

class AttackingFraction: public Fraction {
public:
    void Attack(Fraction& other_fraction, size_t squad_number) const override;
    void Earn(size_t squad_number) override ;
    void Defend(double damage) override;

private:
    Unit* CreateBonusUnit() override;

    const double attacking_coefficient = 1.1;
    const double defending_coefficient = 1.1;
};

//----------------------------------------------------------------------------------------------------------------------

class DefendingFraction: public Fraction {
public:
    void Attack(Fraction& other_fraction, size_t squad_number) const override;
    void Earn(size_t squad_number) override ;
    void Defend(double damage) override;

private:
    Unit* CreateBonusUnit() override;

    const double attacking_coefficient = 0.9;
    const double defending_coefficient = 0.9;
};

//----------------------------------------------------------------------------------------------------------------------

class EconomyFraction: public Fraction {
public:
    void Attack(Fraction& other_fraction, size_t squad_number) const override;
    void Earn(size_t squad_number) override ;
    void Defend(double damage) override;

private:
    Unit* CreateBonusUnit() override;

    const double earning_coefficient = 1.1
};
