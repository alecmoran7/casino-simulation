//
// Created by Alec Moran on 12/30/21.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"
#include <vector>

class Player {
public:
    int startingCash;
    int goalCash;
    int strategyInt;
    Game game;
    bool wasSuccessful;
    vector<int> allRolls;

    Player(int strategyInt, int startAmount, int goalAmount);
    ~Player();
    void playStrategy();

    bool getResult();
};

#endif //PLAYER_H
