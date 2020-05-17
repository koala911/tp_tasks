#include "Player.h"
#include <iostream>


Player::Player(int id): id(id), name(""), fraction(nullptr), is_playing(true) {
    initialize();
    auto add_bonus_unit = new AddBonusUnit;
    auto buy_new_unit = new BuyNewUnit;
    auto army_ruling = new ArmyRuling;
    first_handler = add_bonus_unit;
    add_bonus_unit->SetNextHandler(buy_new_unit);
    buy_new_unit->SetNextHandler(army_ruling);
}

Player::~Player() {
    delete fraction;
    delete first_handler;
}

void Player::MakeMove(std::vector<Player *>& all_players) {
    fraction->CreateNewSquad();
    first_handler->Execute(all_players, id);
}

bool Player::IsPlaying() const {
    return is_playing;
}

void Player::LeaveGame() {
    is_playing = false;
}

IFraction* Player::GetFraction() const {
    return fraction;
}

std::string Player::GetName() const {
    return name;
}

void Player::initialize() {
    std::cout << "Enter your name:" << std::endl;
    std::cin >> name;
    int type_number = 0;
    while (type_number == 0) {
        std::cout << "Choose your type of fraction:\n"
                     "1. Attacking\n"
                     "2. Defending\n"
                     "3. Economy\n"
                     "Print 1, 2 or 3:\n";
        std::cin >> type_number;
        if (type_number == 1) {
            fraction = new AttackingFraction;
        } else if (type_number == 2) {
            fraction = new DefendingFraction;
        } else if (type_number == 3) {
            fraction = new EconomyFraction;
        } else {
            std::cout << "Wrong number!\n"
                         "Try again.\n";
            type_number = 0;
        }
    }
    int information = 0;
    while (information == 0) {
        std::cout << "Do you want to stay informed about events in your fraction?\n"
                     "1. Yes\n"
                     "2. No\n"
                     "Print 1 or 2:\n";
        std::cin >> information;
        if (information == 1) {
            fraction = new InformingDecorator(fraction, name);
        } else if (information != 2) {
            std::cout << "Wrong number!\n"
                         "Try again.\n";
            information = 0;
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------

Handler::Handler(): next_handler(nullptr) {}

Handler::~Handler() {
    delete next_handler;
}

void Handler::SetNextHandler(Handler* handler) {
    next_handler = handler;
}

//----------------------------------------------------------------------------------------------------------------------

void AddBonusUnit::Execute(std::vector<Player*>& all_players, int player_id) {
    auto current_player = all_players[player_id];
    if (current_player->IsPlaying()) {
        auto command = AddBonusUnitCommand(all_players, player_id);
        command.Generate();
        command.Execute();
        if (next_handler != nullptr) {
            next_handler->Execute(all_players, player_id);
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------

void BuyNewUnit::Execute(std::vector<Player*>& all_players, int player_id) {
    auto current_player = all_players[player_id];
    if (current_player->IsPlaying()) {
        bool bought = false;
        do {
            auto command = BuyNewUnitCommand(all_players, player_id);
            command.Generate();
            command.Execute();
            bought = command.Bought();
        } while (bought);
        if (next_handler != nullptr) {
            next_handler->Execute(all_players, player_id);
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------

void ArmyRuling::Execute(std::vector<Player*>& all_players, int player_id) {
    auto current_player = all_players[player_id];
    if (current_player->IsPlaying()) {
        for (std::size_t squad_number = 0; squad_number < current_player->GetFraction()->GetArmySize(); ++squad_number) {
            auto command = ArmyRulingCommand(all_players, player_id, squad_number);
            command.Generate();
            command.Execute();
        }
        if (next_handler != nullptr) {
            std::cout << "wefwdwdc\n";
            next_handler->Execute(all_players, player_id);
        }
    }
}

//----------------------------------------------------------------------------------------------------------------------

Command::Command(std::vector<Player*>& all_players, int player_id): all_players(all_players), player_id(player_id), was_generated(false) {}

//----------------------------------------------------------------------------------------------------------------------

AddBonusUnitCommand::AddBonusUnitCommand(std::vector<Player*>& all_players, int player_id): Command(all_players, player_id) {}

void AddBonusUnitCommand::Generate() {
    IFraction* fraction = all_players[player_id]->GetFraction();
    squad_number = 0;
    while (squad_number == 0) {
        std::cout << "Choose number of squad for your bonus unit (from 1 to " << fraction->GetArmySize() << "):\n";
        std::cin >> squad_number;
        if (squad_number >= 1 && squad_number <= fraction->GetArmySize()) {
            --squad_number;
            break;
        } else {
            std::cout << "Wrong number!\n";
            squad_number = 0;
        }
    }
    was_generated = true;
}

void AddBonusUnitCommand::Execute() {
    if (was_generated) {
        all_players[player_id]->GetFraction()->AddBonusUnit(squad_number);
    } else {
        std::cerr << "Invalid execution of command.\n";
    }
}

//----------------------------------------------------------------------------------------------------------------------

BuyNewUnitCommand::BuyNewUnitCommand(std::vector<Player*>& all_players, int player_id): Command(all_players, player_id), unit_factory(nullptr), bought(false) {}

BuyNewUnitCommand::~BuyNewUnitCommand() {
    delete unit_factory;
}

void BuyNewUnitCommand::Generate() {
    IFraction* fraction = all_players[player_id]->GetFraction();
    squad_number = 0;
    int command = 0;
    bought = false;
    while (command == 0) {
        std::cout << "Do you want to buy a new unit?\n"
                     "1. Yes\n"
                     "2. No\n"
                     "Print 1 or 2:\n";
        std::cin >> command;
        if (command != 1 && command != 2) {
            command = 0;
            std::cout << "Wrong number!\n";
        }
    }
    if (command == 2) {
        unit_factory = nullptr;
        was_generated = true;
        return;
    }
    while (squad_number == 0) {
        int unit_number = 0;
        while (unit_number == 0) {
            std::cout << "Choose type of unit:\n"
                         "1. Civilian " << Civilian::cost << " coins\n"
                         "2. Archer " << Archer::cost << " coins\n"
                         "3. Horse Rider " << HorseRider::cost << " coins\n"
                         "4. Swordsman " << Swordsman::cost << " coins\n"
                         "5. Refuse purchase\n"
                         "Your coins: " << fraction->GetFinance().GetMoney() << "\n"
                         "Print 1, 2, 3, 4 or 5:\n";
            std::cin >> unit_number;
            if (unit_number < 1 || unit_number > 5) {
                unit_number = 0;
                std::cout << "Wrong number!\n";
            }
        }
        if (unit_number == 1) {
            unit_factory = new CivilianFactory;
        } else if (unit_number == 2) {
            unit_factory = new ArcherFactory;
        } else if (unit_number == 3) {
            unit_factory = new HorseRiderFactory;
        } else if (unit_number == 4) {
            unit_factory = new SwordsmanFactory;
        } else if (unit_number == 5) {
            unit_factory = nullptr;
            was_generated = true;
            return;
        }
        if (!fraction->GetFinance().EnoughMoney(unit_factory->GetCost())) {
            std::cout << "Not enough money!\n";
            squad_number = 0;
            continue;
        }
        std::cout << "Choose number of squad for your new unit (from 1 to " << fraction->GetArmySize() << "):\n";
        std::cin >> squad_number;
        if (squad_number >= 1 && squad_number <= fraction->GetArmySize()) {
            --squad_number;
            break;
        } else {
            std::cout << "Wrong number!\n";
            squad_number = 0;
        }
    }
    was_generated = true;
}

void BuyNewUnitCommand::Execute() {
    if (was_generated) {
        if (unit_factory) {
            all_players[player_id]->GetFraction()->BuyUnit(squad_number, *unit_factory);
            delete unit_factory;
            unit_factory = nullptr;
            bought = true;
        }
    } else {
        std::cerr << "Invalid execution of command.\n";
    }
}

bool BuyNewUnitCommand::Bought() const {
    return bought;
}

//----------------------------------------------------------------------------------------------------------------------

ArmyRulingCommand::ArmyRulingCommand(std::vector<Player*>& all_players, int player_id, std::size_t squad_number): Command(all_players, player_id), squad_number(squad_number) {}

void ArmyRulingCommand::Generate() {
    type_of_action = 0;
    while (type_of_action == 0) {
        std::cout << "What to do " << squad_number + 1 << " squad?\n"
                                                      "1. Attack\n"
                                                      "2. Earn money\n"
                                                      "3. Skip this squad\n"
                                                      "Print 1, 2 or 3:\n";
        std::cin >> type_of_action;
        if (type_of_action < 1 || type_of_action > 3) {
            type_of_action = 0;
            std::cout << "Wrong number!\n";
        }
    }
    if (type_of_action == 3) {
        was_generated = true;
        return;
    }
    if (type_of_action == 1) {
        other_player = 0;
        while (other_player == 0) {
            std::cout << "Choose player's number (from 1 to " << all_players.size() << ")\n";
            std::cin >> other_player;
            if (1 > other_player || other_player > all_players.size()) {
                other_player = 0;
                std::cout << "Wrong number!\n";
            }
        }
        --other_player;
    }
    was_generated = true;
}

void ArmyRulingCommand::Execute() {
    if (was_generated) {
        if (type_of_action == 1) {
            all_players[player_id]->GetFraction()->Attack(*all_players[other_player]->GetFraction(), squad_number);
        } else if (type_of_action == 2) {
            all_players[player_id]->GetFraction()->Earn(squad_number);
        } else if (type_of_action == 3) {
            return;
        } else {
            std::cerr << "Invalid type of action in army ruling command.\n";
        }
    } else {
        std::cerr << "Invalid execution of command.\n";
    }
}