#pragma once

#include <string>
#include "Fractions.h"
#include <cstddef>

class Handler;
class Strategy;
class Command;

class Player {
public:
    explicit Player(int id);

    virtual ~Player();

    virtual void MakeMove(std::vector<Player*>& all_players);
    bool IsPlaying() const;
    void LeaveGame();
    IFraction* GetFraction() const;
    std::string GetName() const;
protected:
    IFraction* fraction;
    std::string name;
    int id;
    bool is_playing;
    Handler* first_handler;

    void initialize();
};

//----------------------------------------------------------------------------------------------------------------------

class Handler {
public:
    Handler();
    virtual ~Handler();

    virtual void Execute(std::vector<Player*>& all_players, int player_id) = 0;
    void SetNextHandler(Handler* handler);
protected:
    Handler* next_handler;
};

//----------------------------------------------------------------------------------------------------------------------

class AddBonusUnit: public Handler {
public:
    void Execute(std::vector<Player*>& all_players, int player_id) override;
};

//----------------------------------------------------------------------------------------------------------------------

class BuyNewUnit: public Handler {
public:
    void Execute(std::vector<Player*>& all_players, int player_id) override;
};

//----------------------------------------------------------------------------------------------------------------------

class ArmyRuling: public Handler {
public:
    void Execute(std::vector<Player*>& all_players, int player_id) override;
};

//----------------------------------------------------------------------------------------------------------------------

class Command {
public:
    Command(std::vector<Player*>& all_players, int player_id);

    virtual ~Command() = default;

    virtual void Generate() = 0;
    virtual void Execute() = 0;

protected:
    std::vector<Player*>& all_players;
    int player_id;
    bool was_generated;
};

//----------------------------------------------------------------------------------------------------------------------

class AddBonusUnitCommand: public Command {
public:
    AddBonusUnitCommand(std::vector<Player*>& all_players, int player_id);

    void Generate() override;
    void Execute() override;
private:
    std::size_t squad_number;
};

//----------------------------------------------------------------------------------------------------------------------

class BuyNewUnitCommand: public Command {
public:
    BuyNewUnitCommand(std::vector<Player*>& all_players, int player_id);

    ~BuyNewUnitCommand();

    void Generate() override;
    void Execute() override;
    bool Bought() const;
private:
    std::size_t squad_number;
    UnitFactory* unit_factory;
    bool bought;
};

//----------------------------------------------------------------------------------------------------------------------

class ArmyRulingCommand: public Command {
public:
    ArmyRulingCommand(std::vector<Player*>& all_players, int player_id, std::size_t squad_number);

    void Generate() override;
    void Execute() override;
private:
    std::size_t squad_number;
    int type_of_action;
    int other_player;
};