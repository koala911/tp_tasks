#include "Finance.h"
#include <iostream>

Finance::Finance(): money(0) {}

void Finance::AddMoney(double added_money) {
    money += added_money;
}

void Finance::SpendMoney(double spended_money) {
    if (money - spended_money >= 0) {
        money -= spended_money;
    } else {
        std::cerr << "Not enough money" << std::endl;
    }
}

bool Finance::EnoughMoney(double money) const {
    return money <= this->money;
}

double Finance::GetMoney() const {
    return money;
}