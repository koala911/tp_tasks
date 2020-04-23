#pragma once

#include "Army.h"
#include "Units.h"
#include "Finance.h"

class IFraction {
public:
    virtual ~IFraction() = default;

    virtual void Attack(IFraction& other_fraction, size_t squad_number) const = 0;
    virtual void Earn(size_t squad_number) = 0;
    virtual void Defend(double damage) = 0;

    virtual void CreateNewSquad() = 0;
    virtual void AddBonusUnit(size_t squad_number) = 0;
    virtual bool BuyUnit(size_t squad_number, const UnitFactory& unit_factory) = 0;
    virtual size_t GetArmySize() const = 0;
};

class Fraction: public IFraction {
public:
    explicit Fraction();
    ~Fraction() override;

    void CreateNewSquad() override;
    void AddBonusUnit(size_t squad_number) override;
    bool BuyUnit(size_t squad_number, const UnitFactory& unit_factory) override;
    size_t GetArmySize() const override;

protected:
    Army* const army;
    Finance* const finance;
    int unit_id_counter;

    void AddNewUnit(Unit* const& new_unit, size_t squad_number);
    virtual Unit* CreateBonusUnit() = 0; // фабричный метод для создания нового бонусного юнита
};

//----------------------------------------------------------------------------------------------------------------------

class AttackingFraction: public Fraction {
public:
    void Attack(IFraction& other_fraction, size_t squad_number) const override;
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
    void Attack(IFraction& other_fraction, size_t squad_number) const override;
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
    void Attack(IFraction& other_fraction, size_t squad_number) const override;
    void Earn(size_t squad_number) override ;
    void Defend(double damage) override;

private:
    Unit* CreateBonusUnit() override;

    const double earning_coefficient = 1.1;
};

//----------------------------------------------------------------------------------------------------------------------

// Печатает события, которые происходят во фракции
class InformingDecorator: public IFraction {
public:
    explicit InformingDecorator(IFraction* const& fraction_to_decorate, const std::string& name);
    ~InformingDecorator() override;

    void Attack(IFraction& other_fraction, size_t squad_number) const override;
    void Earn(size_t squad_number) override;
    void Defend(double damage) override;
    void CreateNewSquad() override;
    void AddBonusUnit(size_t squad_number) override;
    bool BuyUnit(size_t squad_number, const UnitFactory& unit_factory) override;
    size_t GetArmySize() const override;

private:
    Fraction* decorated_fraction;
    std::string name;
};
