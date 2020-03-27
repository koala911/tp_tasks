#include "FractionFactory.h"

FractionFactory::FractionFactory(): army(new Army), finance(new Finance), unit_id_counter(0) {}

FractionFactory::~FractionFactory() {
    delete army;
    delete finance;
}

void FractionFactory::AddNewSquad(Squad* const& new_squad) {
    army->AddSquad(new_squad);
}

void FractionFactory::AddNewUnit(Unit *const& new_unit, size_t squad_number) {
    army->AddUnit(new_unit, squad_number);
}

void FractionFactory::AddBonusUnit(size_t squad_number) {
    Unit* new_unit = CreateBonusUnit();
    AddNewUnit(new_unit, squad_number);
}

template<class UnitToBuy>
void FractionFactory::BuyUnit(size_t squad_number) {
    if (UnitToBuy::cost >= finance->GetMoney()) {
        Unit* new_unit = new UnitToBuy(unit_id_counter);
        AddNewUnit(new_unit, squad_number);
        ++unit_id_counter;
        finance->SpendMoney(UnitToBuy::cost);
    } else {
        std::cerr << "Not enough money" << std::endl;
    }
}

size_t FractionFactory::GetArmySize() const {
    return army->GetSize();
}