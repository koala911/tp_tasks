#include "Player.h"

Player::Player(int id): id(id) {
    initializeName();
    initializeFraction();
}

Player::Player(int id, Fraction *const &fraction, const std::string &name): id(id), name(name), fraction(fraction) {}


Player::~Player() {
    delete fraction;
}

void Player::initializeName() {
    std::cout << "Print your name:\n";
    std::getline(std::cin, name);
}

void Player::initializeFraction() {
    bool fraction_initialized = false;
    fraction = nullptr;
    std::string command;
    std::cout << "Choose your type of fraction: Attacking, Defending or Economy\n";
    while (!fraction_initialized) {
        std::getline(std::cin, command);
        if (command == "Attacking") {
            fraction = new AttackingFraction();
            fraction_initialized = true;
        } else if (command == "Defending") {
            fraction = new DefendingFraction();
            fraction_initialized = true;
        } else if (command == "Economy") {
            fraction = new EconomyFraction();
            fraction_initialized = true;
        } else {
            std::cerr << "Wrong type of fraction.\n";
        }
    }
}