#pragma once

#include "Player.h"

class Game {
public:
    Game();
    ~Game();

    void Initialize();
    void StartGame();
private:
    std::vector<Player*> all_players;
};