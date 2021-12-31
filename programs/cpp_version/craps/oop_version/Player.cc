//
// Created by Alec Moran on 12/30/21.
//

#include "Player.h"

using namespace std;

Player::Player(betType strategy, int startingCash, int goalCash) {
    this->startingCash = startingCash;
    this->goalCash = goalCash;
    this->strategy = strategy;
    this->game = Game(Game::strategy, startingCash, goalCash);
}

void playStrategy(){
    Player::wasSuccessful = Player::game.playCraps();
}

bool getResult(){
    return Player::wasSuccessful;
}
