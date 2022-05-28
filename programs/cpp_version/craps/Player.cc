//
// Created by Alec Moran on 12/30/21.
//

#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(int strategyInt, int startingCash, int goalCash) {
//    clog << "Initializing player " << endl;
    this->startingCash = startingCash;
    this->goalCash = goalCash;
    this->strategyInt = strategyInt;
    game = Game(strategyInt, startingCash, goalCash);
//    clog << "player Finished initializing " << endl;
}

Player::~Player(){}

void Player::playStrategy(){
    wasSuccessful = game.playCraps();
}

bool Player::getResult(){
    allRolls = game.dice.allRolls;
    return Player::wasSuccessful;
}
