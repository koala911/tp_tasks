#pragma once

#include "Army.h"
#include "Unit.h"
#include "Finance.h"
#include "AllUnits/IncludeAll.h"

class FractionFactory {
public:
    explicit FractionFactory();
    virtual ~FractionFactory();

    virtual void Attack(FractionFactory& other_fraction, size_t squad_number) const = 0;
    virtual void Earn(size_t squad_number) = 0;
    virtual void Defend(double damage) = 0;

    void AddNewSquad(Squad* const& new_squad);
    void AddBonusUnit(size_t squad_number);
    void AddNewUnit(Unit* const& new_unit, size_t squad_number);
    template<class UnitToBuy>
    void BuyUnit(size_t squad_number);
    size_t GetArmySize() const;

protected:
    Army* const army;
    Finance* const finance;
    int unit_id_counter;

    virtual Unit* CreateBonusUnit() = 0;

};
