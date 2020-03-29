#pragma once

class Finance {
public:
    explicit Finance();
    ~Finance() = default;

    void AddMoney(double added_money);
    void SpendMoney(double spended_money);
    bool EnoughMoney(double money) const;
    double GetMoney() const;

private:
    double money;
};
