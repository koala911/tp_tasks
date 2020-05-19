#include "Game.h"

Game::Game(): all_players(0) {}

Game::~Game() {
    for (auto player: all_players) {
        delete player;
    }
}

void Game::Initialize() {
    int number_of_players = 0;
    while (number_of_players == 0) {
        std::cout << "Print number of players (>= 2):\n";
        std::cin >> number_of_players;
        if (number_of_players < 2) {
            number_of_players = 0;
            std::cout << "Wrong number!\n";
        }
    }
    for (int id = 0; id < number_of_players; ++id) {
        all_players.push_back(new Player(id));
    }
}

void Game::StartGame() {
    while (true) {
        for (auto player: all_players) {
            if (player->IsPlaying()) {
                std::cout << player->GetName() << ", your move!\n";
                player->MakeMove(all_players);
            }
        }
        int count_playing = 0;
        for (auto player: all_players) {
            if (player->GetFraction()->CountUnits() == 0) {
                player->LeaveGame();
            } else {
                ++count_playing;
            }
        }
        if (count_playing < 2) {
            return;
        }
    }
}